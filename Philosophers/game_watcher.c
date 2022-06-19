#include "philosophers.h"

void    death_check(t_data *data, t_philo philo[PHILO_MAX])
{
	int i;
    long long time;

	i = 0;
    time = get_time() - data->time_start;
	pthread_mutex_lock(&data->end_lock);
	while (!data->end && i < data->philo_nb)
	{
		pthread_mutex_unlock(&data->end_lock);
		pthread_mutex_lock(&data->meal_ts);
		if (time - philo[i].last_meal > data->t_die)
		{
            pthread_mutex_lock(&data->print);
			pthread_mutex_lock(&data->end_lock);
			data->end = 1;
			pthread_mutex_unlock(&data->end_lock);
	        printf("%lld %d died\n",
            get_time() - data->time_start, philo[i].i + 1);
            pthread_mutex_unlock(&data->print);
		}
		pthread_mutex_lock(&data->end_lock);
		pthread_mutex_unlock(&data->meal_ts);
        i++;
	}
	pthread_mutex_unlock(&data->end_lock);
}

void    check_meal(t_data *data, t_philo philo[PHILO_MAX])
{
	int i;

	i = 0;
	while(i < data->philo_nb)
	{
		pthread_mutex_lock(&data->meal_ts);
		if(philo[i].meals_done >= data->nb_meals)
			i++;
		else
		{
			pthread_mutex_unlock(&data->meal_ts);
			break ;
		}
		pthread_mutex_unlock(&data->meal_ts);
	}
	if(i == data->philo_nb)
	{
		pthread_mutex_lock(&data->end_lock);
		data->end = 1;	
		pthread_mutex_unlock(&data->end_lock);
	}
}

void	game_watcher(t_data *data, t_philo philo[PHILO_MAX])
{
	int i;

	i = 0;
	pthread_mutex_lock(&data->end_lock);
	while (!data->end)
	{
		pthread_mutex_unlock(&data->end_lock);
        death_check(data, philo);
		if (data->nb_meals >= 0)
			check_meal(data,philo);
		pthread_mutex_lock(&data->end_lock);
	}
	pthread_mutex_unlock(&data->end_lock);
	while (i < data->philo_nb)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
}
