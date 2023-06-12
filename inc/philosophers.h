/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:09:50 by rrask             #+#    #+#             */
/*   Updated: 2023/06/12 19:09:53 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	pthread_t		thread;
	pthread_mutex_t *r_fork;
	pthread_mutex_t *l_fork;
	int				is_dead;
	int				test;
	t_attr			*attributes;
}					t_philo;

// locks that we need
// pthread_mutex_t msg; // lock for printing
// pthread_mutex_t death; // mandatory lock for death checking

/*philos.c*/
void	philos_join(t_philo *philos);
void	philos_spawn(t_philo *philos);
void	philos_init(t_philo *philos, t_attr *attrib, pthread_mutex_t *forks);
void	*philo_run(void *this);



/*utils.c*/
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
// static void	ft_sub(char *str, int len, int n);
// static int	ft_len(int n, int *minus);
// char		*ft_itoa(int n);


/*errors.c*/
void	error_handler(char *str);

/*forks.c*/
void	philos_init(t_philo *philos, t_attr *attrib, pthread_mutex_t *forks);
void	philos_spawn(t_philo *philos);
void	philos_join(t_philo *philos);
void	forks_init(int num_philos, pthread_mutex_t	*forks);
void	forks_destroy(int num_philos, pthread_mutex_t *forks);

#endif