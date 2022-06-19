#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H
#define PHILO_MAX 210

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ctype.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct		s_data
{
	int				philo_nb;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meals;
	long long		time_start;
	int				end;
	pthread_mutex_t	end_lock;
	pthread_mutex_t	fork[PHILO_MAX];
	pthread_mutex_t	meal_ts;
	pthread_mutex_t	print;
}					t_data;

typedef struct		s_philo
{
	int				i;
	int				meals_done;
	long long		last_meal;
	pthread_t		thread;
	t_data			*data;
}					t_philo;

int 				str_isdigit(char *av);
void				p_usleep(int time, t_data *data);
long long			get_time(void);
void    			display(char *message, t_data *data, int i);
int					data_init(int ac, char **av, t_data *data, t_philo philo[PHILO_MAX]);
int					parsing_checks(int ac, char **av);
void				game_watcher(t_data *data, t_philo philo[PHILO_MAX]);

#endif