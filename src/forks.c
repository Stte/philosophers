/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:19:57 by rrask             #+#    #+#             */
/*   Updated: 2023/06/12 16:24:41 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	forks_init(int num_philos, pthread_mutex_t	*forks)
{
	int i;

	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(forks + i, NULL) != 0)
			error_handler("No philosophers here.");
		i++;
	}
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