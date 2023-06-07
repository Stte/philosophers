#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ARG_MIN 4
# define RAS_MAX 2147483647
# define RAS_MIN -2147483648
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

pthread_mutex_t my_mutex;

/*Philo utils*/
int		ft_atoi(const char *str);

/*Philo errors*/
void	error_handler(char *str);

/*Philo main components*/

#endif