/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheepoofi <junheepoofi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:51:23 by rrask             #+#    #+#             */
/*   Updated: 2023/06/12 16:28:02 by junheepoofi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int counter = 0;

void	attr_set(t_attr *attrib, int argc, char **argv)
{
	attrib->philo_num = ft_atoi(argv[1]);
	attrib->time_to_die = ft_atoi(argv[2]);
	attrib->time_to_eat =  ft_atoi(argv[3]);
	attrib->time_to_sleep =  ft_atoi(argv[4]);
	if (argc == ARG_MAX)
		attrib->eat_amount =  ft_atoi(argv[5]);
	attrib->eat_amount = -1;
}

void *thread_func(void *this)
{
	int		test = 0;
	int *philo = (int *)this;
	
	printf("philo %d will start working\n", *philo);
	while (test < 10)
	{
		test++;
		pthread_mutex_lock(&my_mutex);
		counter++;
		printf("Philo %d is counting: %d.\n", *philo, counter);
		pthread_mutex_unlock(&my_mutex);
	}
	return (this);
}

void	philo_spawn(void)
{
	int i = 0;
	
	pthread_t th[4];
	
	while (i < 4)
	{
		printf("i: %d\n", i);
		printf("Philosopher %d has begun.\n", i);
		pthread_create(&th[i], NULL, &thread_func, &i); //The i needs to be ITOA'd so it is allocated. 
		i++;
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(th[i], NULL);
		printf("Philosopher %d has been terminated.\n", i);
		i++;
	}
}

void	philos_init(t_philo *philos, t_attr *attrib, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < attrib->philo_num)
	{
		philos[i].attributes = attrib;
		philos[i].l_fork = &forks[i];
		if (i == attrib->philo_num - 1)
			philos[i].r_fork = &forks[0];
		else
			philos[i].r_fork = &forks[i + 1];
		i++;
	}
}

int main (int argc, char **argv)
{
	t_attr			attributes;
	pthread_mutex_t	forks[MAX_PHILO];
	t_philo			philos[MAX_PHILO];

	if (argc < ARG_MIN || argc > ARG_MAX)
	{
		printf("lol");
		return (0);
	}
	printf("life's good");
	attr_set(&attributes, argc, argv);
	forks_init(attributes.philo_num, forks);
	philos_init(philos, &attributes, forks);
	// philo_spawn();
	forks_destroy(attributes.philo_num, forks);
	return (0); 
}
// where do we create the t_philos? A: After/before fork
// Each philo needs attrib