/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:04:08 by rrask             #+#    #+#             */
/*   Updated: 2022/11/16 17:56:32 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bcpy;

	bcpy = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bcpy[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
