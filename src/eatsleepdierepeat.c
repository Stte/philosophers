/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eatsleepdierepeat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvn-den <nvn-den@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 11:23:43 by rrask             #+#    #+#             */
/*   Updated: 2023/06/16 14:57:26 by nvn-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print_state(t_philo *philo,  char *string)
{
	size_t lapsed_time;

	pthread_mutex_lock(philo->print);
	lapsed_time = get_time_ms() - philo->attr->start_time;
	printf("%zu %d %s\n", lapsed_time, philo->id, string);
	pthread_mutex_unlock(philo->print);
}

int	ft_usleep(t_philo *philo, size_t time_to_snooze)
{
	size_t	the_time;

	the_time = get_time_ms();
	pthread_mutex_lock(philo->death);
	while (!(philo->is_dead) && (get_time_ms() - the_time) < time_to_snooze)
	{
		pthread_mutex_unlock(philo->death);
		usleep(500);
	}
	return (0);
}


void	eating(t_philo *philo, size_t time_to_eat)
{
	size_t	last_supper;

	last_supper = get_time_ms();
	print_state(philo, "is eating");
	ft_usleep(philo, time_to_eat);
	if (philo->is_dead)
		return ; //Stop everything
	philo->last_supper = last_supper;
	philo->times_eaten += 1;
}

void	hit_the_hay(t_philo *philo)
{
	print_state(philo, "is sleeping");
	ft_usleep(philo, philo->attr->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
	// ft_usleep(philo, 1);
}
