#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ARG_MIN 4
# define RAS_MAX 2147483647
# define RAS_MIN -2147483648
# define PHILO_NUM 200
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

pthread_mutex_t my_mutex;

typedef struct s_philo
{
	pthread_mutex_t *right;
	pthread_mutex_t left;
	int	time_to_sleep;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_think;
}					t_philo;


/*Philo utils*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/*Philo errors*/
void	error_handler(char *str);

/*Philo main components*/

#endif