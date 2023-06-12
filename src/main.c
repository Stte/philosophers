/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junheepoofi <junheepoofi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 09:51:23 by rrask             #+#    #+#             */
/*   Updated: 2023/06/12 16:28:02 by junheepoofi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	attr_set(t_attr *attrib, int argc, char **argv)
{
	attrib->philo_num = ft_atoi(argv[1]);
	attrib->time_to_die = ft_atoi(argv[2]);
	attrib->time_to_eat =  ft_atoi(argv[3]);
	attrib->time_to_sleep =  ft_atoi(argv[4]);
	if (argc == ARG_MAX)
		attrib->eat_amount =  ft_atoi(argv[5]);
	attrib->eat_amount = -1;
}

int main (int argc, char **argv)
{
	t_attr			attributes;
	pthread_mutex_t	forks[MAX_PHILO];
	t_philo			philos[MAX_PHILO];

	if (argc < ARG_MIN || argc > ARG_MAX)
	{
		printf("lol");
		return (0);
	}
	printf("life's good");
	attr_set(&attributes, argc, argv);
	forks_init(attributes.philo_num, forks);
	philos_init(philos, &attributes, forks);
	philos_spawn(philos);
	// loop the philos to check if philos have died
	philos_join(philos);
	forks_destroy(attributes.philo_num, forks);
	return (0); 
}
