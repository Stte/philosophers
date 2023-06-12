/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:51:23 by rrask             #+#    #+#             */
/*   Updated: 2023/06/12 15:36:30 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int counter = 0;

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

void	create_threads(void)
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

pthread_mutex_t	*forks_init(int num_philos)
{
	int i;
	pthread_mutex_t *forks;

	forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	if (!forks)
		return(NULL);
	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(forks + i, NULL) != 0)
			error_handler("No philosophers here.");
		i++;
	}
	return (forks);
}

void	forks_destroy(int num_philos, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(forks + i) != 0)
			error_handler("Mutex is too powerful, we have failed in vanquishing it...");
		i++;
	}
}

void	set_args(t_attr *attrib, char **argv)
{
	attrib->philo_num = argv[1];
	attrib->time_to_die = argv[2];
	attrib->time_to_eat = argv[3];
	attrib->time_to_sleep = argv[4];
	attrib->eat_amount = argv[5];
}



int main (int argc, char **argv)
{
	pthread_mutex_t	*forks;
	t_attr			attributes;
	
	if (argc < 5 || argc > 6)
		return (0);
	set_args(&attributes, argv);
	// philo_init(&philos);
	forks = forks_init(attributes.philo_num);
	create_threads();
	forks_destroy(attributes.philo_num, forks);
	free(forks);
	return (0); 

// where do we create the t_philos? A: After/before fork
// Each philo needs attrib