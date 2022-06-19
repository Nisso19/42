#include "philosophers.h"

int str_isdigit(char *av)
{
	int i;

	i = 0;
	while(av[i])
	{
		if (av[i] < '0' || av[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void p_usleep(int time, t_data *data)
{
	struct timeval start_tv;
	struct timeval curr_tv;
	long long start;
	long long curr;

	gettimeofday(&start_tv, NULL);
	start = start_tv.tv_sec * 1000 + (start_tv.tv_usec / 1000);
	gettimeofday(&curr_tv, NULL);
	curr = curr_tv.tv_sec * 1000 + (curr_tv.tv_usec / 1000);
	pthread_mutex_lock(&data->end_lock);
	while (curr < start + time && !data->end)
	{
		pthread_mutex_unlock(&data->end_lock);
		usleep(500);
		gettimeofday(&curr_tv, NULL);
		curr = curr_tv.tv_sec * 1000 + (curr_tv.tv_usec / 1000);
		pthread_mutex_lock(&data->end_lock);
	}
	pthread_mutex_unlock(&data->end_lock);
}

long long  get_time(void)
{
    struct timeval	tv;
    long long		time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + (tv.tv_usec / 1000);
    return (time);
}

void    display(char *message, t_data *data, int i)
{
	long long time;

    pthread_mutex_lock(&data->print);
	pthread_mutex_lock(&data->end_lock);
	if (data->end)
	{
		pthread_mutex_unlock(&data->print);
		pthread_mutex_unlock(&data->end_lock);
		return ;
	}
	time = get_time();
	printf("%lld %d %s", time - data->time_start, i + 1, message);
    pthread_mutex_unlock(&data->print);
	pthread_mutex_unlock(&data->end_lock);
}

int parsing_checks(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 5 || ac > 6  || !str_isdigit(av[1]) || !str_isdigit(av[2])
	|| !str_isdigit(av[3]) || !str_isdigit(av[4]) || (ac == 6 && !str_isdigit(av[5])))
	{
		printf("Mauvais argument\n");
		return(0);
	}
	if (atoi(av[1]) > 200)
	{
		printf("Too many philosophers !\n");
		return (0);
	}
	return (1);
}
