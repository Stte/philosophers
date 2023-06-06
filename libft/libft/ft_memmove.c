/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:52:59 by rrask             #+#    #+#             */
/*   Updated: 2022/12/14 15:59:40 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*a;
	char	*b;

	if (dst == NULL && src == NULL)
		return (NULL);
	a = (char *)dst;
	b = (char *)src;
	if (a > b)
	{
		while (n--)
			a[n] = b[n];
	}
	else
	{
		while (n--)
			*(a++) = *(b++);
	}
	return (dst);
}
