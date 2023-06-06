/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:57:01 by rrask             #+#    #+#             */
/*   Updated: 2022/12/14 17:37:24 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	inputlen(int n)
{
	int		len;
	long	newn;

	len = 0;
	newn = (long)n;
	if (n == 0)
		return (1);
	if (newn < 0)
		len++;
	while (newn != 0)
	{
		newn /= 10;
		len++;
	}
	return (len);
}

static long	newnzero(long newn, int mod, int len, char *nbr)
{
	while (newn != 0)
	{
		mod = newn % 10;
		newn = newn / 10;
		nbr[len - 1] = mod + '0';
		len--;
	}
	return (newn);
}

char	*ft_itoa(int n)
{
	int		len;
	int		mod;
	long	newn;
	char	*nbr;

	len = inputlen(n);
	mod = 0;
	newn = (long)n;
	nbr = malloc(sizeof(char) * len + 1);
	if (!nbr)
		return (NULL);
	if (newn == 0)
		nbr[0] = '0';
	nbr[len] = '\0';
	if (newn < 0)
	{
		newn = newn * -1;
		nbr[0] = '-';
	}
	newnzero(newn, mod, len, nbr);
	return (nbr);
}
