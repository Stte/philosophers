#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define ARG_MIN 5
# define ARG_MAX 6
# define RAS_MAX 2147483647
# define RAS_MIN -2147483648
# define MAX_PHILO 250
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h> // isdigit
# include <unistd.h>

pthread_mutex_t my_mutex;

typedef struct s_attr
{
	int	philo_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	eat_amount;
}					t_attr;

typedef struct s_philo
{
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	t_attr			*attributes;
}					t_philo;

// locks that we need
// pthread_mutex_t forks[]; // fork array
// pthread_mutex_t msg; // lock for printing
// pthread_mutex_t death; // mandatory lock for death checking


/*Philo utils*/
int		ft_atoi(const char *str);
int		ft_isdigit(int c);

/*Philo errors*/
void	error_handler(char *str);

/*Philo main components*/
void	philos_init(t_philo *philos, t_attr *attrib, pthread_mutex_t *forks);
void	forks_init(int num_philos, pthread_mutex_t	*forks);
void	forks_destroy(int num_philos, pthread_mutex_t *forks);

#endif