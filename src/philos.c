/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:50:58 by rrask             #+#    #+#             */
/*   Updated: 2023/06/12 19:05:10 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	*philo_run(void *this)
{
	t_philo	*philo = (t_philo *)this;
	
	pthread_mutex_lock(philo->l_fork);
	printf("Philo: %d.\n", philo->test);
	pthread_mutex_unlock(philo->l_fork);

	return (this);
}


void	philos_init(t_philo *philos, t_attr *attrib, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < attrib->philo_num)
	{
		philos[i].attributes = attrib;
		philos[i].l_fork = &forks[i];
		if (i == attrib->philo_num - 1)
			philos[i].r_fork = &forks[0];
		else
			philos[i].r_fork = &forks[i + 1];
		philos[i].is_dead = 0;
		philos[i].test = i;
		i++;
	}
}

void	philos_spawn(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos->attributes->philo_num)
	{
		pthread_create(&philos[i].thread, NULL, &philo_run, philos + i);
		i++;
	}
	
}

void	philos_join(t_philo *philos)
{
	int i;

	i = 0;
	while (i < philos->attributes->philo_num)
	{
		pthread_join(philos[i].thread, NULL);
		printf("Philosopher %d has been terminated.\n", i);
		i++;
	}
}