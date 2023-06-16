/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   governor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:27:41 by rrask             #+#    #+#             */
/*   Updated: 2023/06/16 14:12:35 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

static	void dead_philo_check(t_philo *philos, t_attr *attr)
{
	int i;

	i = 0;
	while (i < attr->philo_num)
	{
		if (is_dead(philos[i].last_supper, attr->time_to_die) == 1)
			printf("Philosopher %d is dead.\n", philos[i].id);
		i++;
	}
}

void	governor(t_philo *philos, t_attr *attr, pthread_mutex_t	*forks)
{
	int i;

	i = 0;
	(void)forks;
	while (1)
	{
		dead_philo_check(philos, attr);
	}
}
