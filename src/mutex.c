/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:19:57 by rrask             #+#    #+#             */
/*   Updated: 2023/06/21 14:14:13 by tspoof           ###   ########.fr       */
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
			error_handler("No gate here.");
	if (pthread_mutex_init(&mutex->death, NULL) != 0)
			error_handler("No death here.");
}

void	mutex_destroy(int num_philos, t_mutex *mutex)
{
	forks_destroy(num_philos, mutex->forks);
	if (pthread_mutex_destroy(&mutex->gate) != 0)
			error_handler("Mutex is too powerful, we have failed in vanquishing it...");
	if (pthread_mutex_destroy(&mutex->death) != 0)
			error_handler("Mutex is too powerful, we have failed in vanquishing it...");
}
