/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:19:57 by rrask             #+#    #+#             */
/*   Updated: 2023/06/24 21:04:33 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

static void	mutex_array_init(int num_philos, pthread_mutex_t *mutexes)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(mutexes + i, NULL) != 0)
			error_handler("Mutex init failed.");
		i++;
	}
}

void	mutex_array_destroy(int num_philos, pthread_mutex_t *mutexes)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_destroy(mutexes + i) != 0)
			error_handler("Mutex init failed.");
		i++;
	}
}

void	mutex_init(int num_philos, t_mutex *mutex)
{
	mutex_array_init(num_philos, mutex->forks);
	mutex_array_init(num_philos, mutex->deaths);
	if (pthread_mutex_init(&mutex->gate, NULL) != 0)
			error_handler("No forks here.");
	if (pthread_mutex_init(&mutex->print, NULL) != 0)
			error_handler("No forks here.");
}

void	mutex_destroy(int num_philos, t_mutex *mutex)
{
	mutex_array_destroy(num_philos, mutex->forks);
	mutex_array_destroy(num_philos, mutex->deaths);
	if (pthread_mutex_destroy(&mutex->gate) != 0)
			error_handler("Mutex init failed.");
	if (pthread_mutex_destroy(&mutex->print) != 0)
			error_handler("Mutex init failed.");
}