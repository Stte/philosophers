/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:59:42 by rrask             #+#    #+#             */
/*   Updated: 2022/12/14 17:42:16 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	a = (char *)dst;
	b = (char *)src;
	if (!n || dst == src)
		return (a);
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
