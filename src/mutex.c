/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:19:57 by rrask             #+#    #+#             */
/*   Updated: 2023/06/21 11:20:30 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

static void	forks_init(int num_philos, pthread_mutex_t	*forks)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(forks + i, NULL) != 0)
			error_handler("No forks here.");
		i++;
	}
}

static void	forks_destroy(int num_philos, pthread_mutex_t *forks)
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

void	mutex_init(int num_philos, t_mutex *mutex)
{
	forks_init(num_philos, mutex->forks);
	if (pthread_mutex_init(&mutex->gate, NULL) != 0)
			error_handler("No forks here.");
	if (pthread_mutex_init(&mutex->death, NULL) != 0)
			error_handler("No forks here.");
}

void	mutex_destroy(int num_philos, t_mutex *mutex)
{
	forks_destroy(num_philos, mutex->forks);
	if (pthread_mutex_destroy(&mutex->gate) != 0)
			error_handler("Mutex is too powerful, we have failed in vanquishing it...");
}