/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:15:18 by rrask             #+#    #+#             */
/*   Updated: 2023/06/07 15:35:38 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"
# include <ctype.h>

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (isdigit(*str)) // CHANGE TO FT_ISDIGIT AND REMOVE CTYPE LIB
	{
		res = res * 10 + *str - '0';
		if (res * sign > RAS_MAX)
			return (-1);
		else if (res * sign < RAS_MIN)
			return (0);
		str++;
	}
	return ((int)res * sign);
}