
#include "philosophers.h"

void	philo_even_eating(t_philo *philo)
{
	t_data	*data;
	int		i;
	int		y;

	data = philo->data;
	i = philo->i;
	y = i + 1;
	if (i == data->philo_nb - 1)
		y = 0;
	pthread_mutex_lock(&data->fork[i]);
	display("has taken a fork\n", data, i);
	pthread_mutex_lock(&data->fork[y]);
	display("has taken a fork\n", data, i);
	pthread_mutex_lock(&data->meal_ts);
	display("is eating\n", data, i);
	philo->last_meal = get_time() - data->time_start;
	philo->meals_done += 1;
	pthread_mutex_unlock(&data->meal_ts);
	p_usleep(data->t_eat, data);
	pthread_mutex_unlock(&data->fork[i]);
	pthread_mutex_unlock(&data->fork[y]);
}

void	philo_odd_eating(t_philo *philo)
{
	t_data	*data;
	int		i;
	int		y;

	data = philo->data;
	i = philo->i;
	y = i + 1;
	if (i == data->philo_nb - 1)
		y = 0;
	pthread_mutex_lock(&data->fork[y]);
	display("has taken a fork\n", data, i);
	pthread_mutex_lock(&data->fork[i]);
	display("has taken a fork\n", data, i);
	pthread_mutex_lock(&data->meal_ts);
	display("is eating\n", data, i);
	philo->last_meal = get_time() - data->time_start;
	philo->meals_done += 1;
	pthread_mutex_unlock(&data->meal_ts);
	p_usleep(data->t_eat, data);
	pthread_mutex_unlock(&data->fork[y]);
	pthread_mutex_unlock(&data->fork[i]);
}

void	philo_sleeping(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	display("is sleeping\n", data, philo->i);
	p_usleep(data->t_sleep, data);
	display("is thinking\n", data, philo->i);
	p_usleep(2, data);
}

void	*philo_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo*)arg;
	if (philo->data->philo_nb == 1)
		p_usleep(philo->data->t_die, philo->data);
	if (philo->i % 2 == 1)
	{
		p_usleep(philo->data->t_eat, philo->data);
	}
	pthread_mutex_lock(&philo->data->end_lock);
	while (!philo->data->end)
	{
		pthread_mutex_unlock(&philo->data->end_lock);
		if (philo->i % 2 == 1)
			philo_odd_eating(philo);
		else
			philo_even_eating(philo);
		philo_sleeping(philo);
		pthread_mutex_lock(&philo->data->end_lock);
	}
	pthread_mutex_unlock(&philo->data->end_lock);
	pthread_exit(NULL);
}

int setup_threads(t_data *data, t_philo philo[PHILO_MAX])
{
	int i;

	i = 0;	
    while(i < (data->philo_nb))
    {
		if (pthread_create(&philo[i].thread, NULL, philo_routine, &philo[i]))
			return (0);
		i++;
    }
	return (1);
}

int main(int ac, char **av)
{
	int i;
	t_data		data;
	t_philo		philo[PHILO_MAX];

	i = -1;
	if (!parsing_checks(ac, av)
	|| !data_init(ac, av, &data, philo)
	|| !setup_threads(&data, philo))
		return (-1);
	game_watcher(&data, philo);
	pthread_mutex_destroy(&data.meal_ts);
	pthread_mutex_destroy(&data.print);
	while (++i < data.philo_nb)
		pthread_mutex_destroy(&data.fork[i]);
	return (0);
}
