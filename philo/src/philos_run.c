/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:15:38 by tspoof            #+#    #+#             */
/*   Updated: 2023/06/21 14:23:53 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philo_even(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	eating(philo, philo->attr->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	philo_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->l_fork);
	eating(philo, philo->attr->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*philo_run(void *this)
{
	t_philo	*philo = (t_philo *)this;

	pthread_mutex_lock(philo->gate);
	pthread_mutex_unlock(philo->gate);
	while (1)
	{
		if (philo->attr->times_must_eat >= 0
			&& philo->times_eaten >= philo->attr->times_must_eat)
		{
			printf("Philosopher %d has eaten enough.\n", philo->id);
			return (0);
		}
		if (is_dead(philo, philo->attr->time_to_die))
			return (0);
		if (philo->id % 2 == 0)
			philo_even(philo);
		else
			philo_odd(philo);
		sleeping(philo, philo->attr->time_to_sleep);
	}
	return (this);
}
