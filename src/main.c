/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheepoofi <junheepoofi@student.hive.fi>        +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:51:23 by rrask             #+#    #+#             */
/*   Updated: 2023/06/12 16:28:02 by junheepoofi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	attr_set(t_attr *attr, int argc, char **argv)
{
	// if (attr->philo_num <= 0 || attr->time_to_die <= 0 || attr->time_to_eat <= 0
	// 	|| attr -> time_to_sleep <= 0 || attr -> eat_amount <= 0)
	// {
	// 	printf("Arguments are invalid\n");
	// 	return ;
	// }
	attr->philo_num = ft_atoi(argv[1]);
	attr->time_to_die = ft_atoi(argv[2]);
	attr->time_to_eat = ft_atoi(argv[3]);
	attr->time_to_sleep = ft_atoi(argv[4]);
	if (argc == ARG_MAX)
		attr->eat_amount = ft_atoi(argv[5]);
	attr->eat_amount = -1;
	attr->start_time = get_time_ms();
}

int	main(int argc, char **argv)
{
	t_attr			attributes;
	t_mutex			mutex;
	// pthread_mutex_t	forks[MAX_PHILO];
	t_philo			philos[MAX_PHILO];

	if (argc < ARG_MIN || argc > ARG_MAX)
	{
		printf("Try again, punk.\n");
		return (0);
	}
	attr_set(&attributes, argc, argv);
	// forks_init(attributes.philo_num, mutex.forks);
	mutex_init(attributes.philo_num, &mutex);
	philos_init(philos, &attributes, &mutex);
	philos_spawn(philos, &mutex.gate);
	governor(philos, &attributes, mutex.forks);
	// loop the philos to check if philos have died
	philos_join(philos);
	mutex_destroy(attributes.philo_num, &mutex);
	// forks_destroy(attributes.philo_num, forks);
	return (0);
}
