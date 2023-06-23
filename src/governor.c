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

static int	dead_philo_check(t_philo *philos, t_attr *attr)
{
	int i;

	i = 0;
	while (i < attr->philo_num)
	{
		if (philos[i].is_dead == 1)
		{
			//while the other philos don't have is_dead == 1, set them to is_dead = 1.
			print_state(philos[i].attr->start_time, &philos[i], "died");
			//How to tell philos to stop eating and exit?
			return (1);
		}
		i++;
	}
	return (0);
}

void	governor(t_philo *philos, t_attr *attr, t_mutex *mutex)
{
	int i;

	i = 0;
	(void)mutex;
	if (dead_philo_check(philos, attr))
		return ;
	if (attr->times_must_eat)
	{
		if (philos[i].times_eaten == attr->times_must_eat)
		{
			printf("Philosopher %d has eaten enough.\n", philos[i].id);
			return ;
		}
	}
	return ;
}
