#include "philosophers.h"


void	philos_init(t_data *data, t_philo philo[PHILO_MAX])
{
    int     i;

    i = 0;
    while (i < data->philo_nb)
    {
        philo[i].i = i;
        philo[i].meals_done = 0;
        philo[i].last_meal = 0;
        philo[i].data = data;
		i++;
    }
}

int fork_init(t_data *data)
{
	int y;

	y = 0;
	while (y < data->philo_nb)
	{
		if (pthread_mutex_init(&data->fork[y], NULL) != 0)
			return (0);
		y++;
	}
	return (1);
}

int     data_init(int ac, char **av, t_data *data, t_philo philo[PHILO_MAX])
{
	struct timeval tv;			// voir pour le déplacer au moment où les philo commencent
	gettimeofday(&tv, NULL);	//
	data->time_start = tv.tv_sec * 1000 + (tv.tv_usec / 1000);	//

	data->philo_nb = atoi(av[1]);		// remplacer par ft_atoi
	data->t_die = atoi(av[2]);			// remplacer par ft_atoi
	data->t_eat = atoi(av[3]);			// remplacer par ft_atoi
	data->t_sleep = atoi(av[4]);		// remplacer par ft_atoi
	data->end = 0;
	if (ac == 6)
		data->nb_meals = atoi(av[5]);	// remplacer par ft_atoi
	else
		data->nb_meals = -1;
	if (fork_init(data) == 0
	|| pthread_mutex_init(&data->end_lock, NULL) != 0
	|| pthread_mutex_init(&data->meal_ts, NULL) != 0
	|| pthread_mutex_init(&data->print, NULL) != 0)
	{
		printf("\n mutex init failed\n");
        return (0);
	}
    philos_init(data, philo);
    return (1);
}