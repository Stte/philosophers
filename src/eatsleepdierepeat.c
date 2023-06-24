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

void	print_state(size_t start_time, int philo_num, char *string)
{
	size_t lapsed_time;

	// print lock?
	lapsed_time = get_time_ms() - start_time;
	printf("%zu %d %s\n", lapsed_time, philo_num, string);
}

int	ft_usleep(t_philo *philo, size_t time_to_snooze)
{
	size_t	the_time;

	the_time = get_time_ms();
	while (!(philo->is_dead) && (get_time_ms() - the_time) < time_to_snooze)
	{
		usleep(500);
	}
		//cha cha real smooth (it's 500 microseconds)
		//What is this? A crossover episode?
	return (0);
}


void	eating(t_philo *philo, size_t time_to_eat)
{
	size_t	last_supper;

	last_supper = get_time_ms();
	// printf("last supper was: %zu\n", get_time_ms());
	// printf("Philo %i has eaten %i times\n",philo->id, philo->times_eaten);
	print_state(philo->attr->start_time, philo->id, "is eating");
	ft_usleep(philo, time_to_eat);
	// if (is_dead(philo, philo->attr->time_to_die) == 1)
	if (philo->is_dead)
		return ; //Stop everything
	philo->last_supper = last_supper;
	philo->times_eaten += 1;
}

void	hit_the_hay(t_philo *philo)
{
	print_state(philo->attr->start_time, philo->id, "is sleeping");
	ft_usleep(philo, philo->attr->time_to_sleep);
}

void	thinking(t_philo *philo)
{
	print_state(philo->attr->start_time, philo->id, "is thinking");
	// ft_usleep(philo, 1);
}
