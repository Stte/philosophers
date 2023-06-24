/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   governor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:51:33 by rrask             #+#    #+#             */
/*   Updated: 2023/06/23 12:41:556 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int	is_dead(t_philo *philo, size_t time_to_die)
{
	if (get_time_ms() - philo->last_supper >= time_to_die)
		return (1);
	return (0);
}

void	kill_all(t_philo *philos, int idx)
{
	int i;

	// pthread_mutex_unlock(philos[idx].death);
	i = 0;
	while (i < philos[0].attr->philo_num)
	{
		if (i == idx)
		{
			philos[i].is_dead = 1;
			i++;
		}
		pthread_mutex_lock(philos[i].death);
		if (!philos[i].is_dead)
			philos[i].is_dead = 1;
		pthread_mutex_unlock(philos[i].death);
		i++;
	}
}

int	dead_philo_check(t_philo *philos, t_attr *attr)
{
	int i;

	i = 0;
	while (i < attr->philo_num)
	{
		pthread_mutex_lock(philos[i].death);
		if (is_dead(&philos[i], attr->time_to_die))
		{
			kill_all(philos, i);
			pthread_mutex_unlock(philos[i].death);
			print_state(philos + i, "has died");
			return (1);
		}
		pthread_mutex_unlock(philos[i].death);
		i++;
	}
	return (0);
}

void	governor(t_philo *philos, t_attr *attr, t_mutex *mutex)
{
	int i;

	i = 0;
	(void)mutex;
	while (1)
	{
		if (dead_philo_check(philos, attr))
			return ;
		if (attr->times_must_eat >= 0
			&& philos[i].times_eaten == attr->times_must_eat)
		{
			print_state( philos + i, "has eaten enough");
			return ;
		}
	}
	return ;
}
