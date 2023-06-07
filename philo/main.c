/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:51:23 by rrask             #+#    #+#             */
/*   Updated: 2023/06/07 15:30:46 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int counter = 0;

void *thread_func(void *this)
{

	pthread_mutex_lock(&my_mutex);
	while (counter < 4000000)
	{
		counter++;
	}
	pthread_mutex_unlock(&my_mutex);
	return (this);
}

void	create_threads(void)
{
	int i = 0;
	pthread_t th[4];
	while (i < 4)
	{
		pthread_create(&th[i], NULL, &thread_func, NULL);
		i++;
		printf("Thread %d has begun.\n", i);
	}
	printf("Counter is: %d.\n", counter);
	i = 0;
	while (i < 4)
	{
		pthread_join(th[i], NULL);
		i++;
		printf("Thread %d has been terminated.\n", i);
	}
}

int main (int argc, char **argv)
{
	int i = 0;

	if (argc == 3)
	{
		if (pthread_mutex_init(&my_mutex, NULL) != 0)
			error_handler("No threads here.");	
		i = ft_atoi(argv[2]);
		printf("We now have thread capability.\n");
		create_threads();
		printf("Counter is: %d.\n", counter);
		if (pthread_mutex_destroy(&my_mutex) != 0)
			error_handler("Mutex is too powerful, we have failed in vanquishing it...");
		printf("We have vanquished the mutex.\n");
	}
	return (0);
}