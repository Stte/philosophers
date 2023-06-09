/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:51:23 by rrask             #+#    #+#             */
/*   Updated: 2023/06/09 11:20:39 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <unistd.h>

int counter = 0;

void *thread_func(void *this)
{
	pthread_t philo = pthread_self();
	int		test = 0;
	// printf("Philo %lu is accessing this shared function.\n", (unsigned long)philo);
	while (test < 10)
	{
		test++;
		pthread_mutex_lock(&my_mutex);
		counter++;
		printf("Philo %lu is counting: %d.\n", (unsigned long)philo, counter);
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
		pthread_create(&th[i], NULL, &thread_func, (void*)&th[i]);
		i++;
		printf("Philosopher %d has begun.\n", i);
	}
	i = 0;
	while (i < 4)
	{
		pthread_join(th[i], NULL);
		i++;
		printf("Philosopher %d has been terminated.\n", i);
	}
}

void	philo_init(t_philo (*philos)[10])
{
	int i = 0;

	while (i < 10)
	{
		if (pthread_mutex_init(&(philos[i]->left), NULL) != 0)
			error_handler("No philosophers here.");	
		i++;
	}
	i = 0;
	while (i < 10)
	{
		if (i == 9)
			philos[i]->right = &philos[0]->left;
		else
			philos[i]->right = &philos[i+1]->left;
		i++;
	}
}

int main (int argc, char **argv)
{
	t_philo philos[10];
	(void) argv[2];
	if (argc == 3)
	{
		philo_init(&philos);
		// create_threads();
		// printf("Counter is: %d.\n", counter);
		// if (pthread_mutex_destroy(&my_mutex) != 0)
		// 	error_handler("Mutex is too powerful, we have failed in vanquishing it...");
		// printf("We have vanquished the mutex.\n");
	}
	return (0);
}