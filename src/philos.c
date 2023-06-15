/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:50:58 by rrask             #+#    #+#             */
/*   Updated: 2023/06/15 16:01:55 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	*philo_run(void *this)
{
	//Start the philosopher logic here (Grab forks if odd number, \\
		eat if two forks, die if death is due, wait if only one fork.)
	t_philo	*philo = (t_philo *)this;
	
	// wait for the philos to unlock
	
	
	if (philo->id % 2 == 0)
		//lock the right fork first, have them dine.
	// else
		//Lock the left fork first.
	pthread_mutex_lock(philo->l_fork);
	printf("Philo: %d.\n", philo->id);
	pthread_mutex_unlock(philo->l_fork);

	return (this);
}


void	philos_init(t_philo *philos, t_attr *attrib, pthread_mutex_t *forks)
{
	int i;

	i = 0;
	while (i < attrib->philo_num)
	{
		if (pthread_mutex_init(philos[i].gate, NULL) != 0)
			error_handler("No philosophers here.");
		philos[i].attributes = attrib;
		philos[i].l_fork = &forks[i];
		if (i == attrib->philo_num - 1)
			philos[i].r_fork = &forks[0];
		else
			philos[i].r_fork = &forks[i + 1];
		philos[i].id = i;
		philos[i].last_supper = get_time_ms();
		i++;
	}
}

void	philos_spawn(t_philo *philos)
{
	int i;

	i = 0;
	
	// lock philos here
	while (i < philos->attributes->philo_num)
	{
		pthread_create(&philos[i].thread, NULL, &philo_run, philos + i);
		i++;
	}
	// unlock philos here
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