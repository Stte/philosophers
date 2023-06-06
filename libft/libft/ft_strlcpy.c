/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:49:41 by rrask             #+#    #+#             */
/*   Updated: 2022/12/05 14:31:49 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = 0;
	while (src[srclen] != '\0')
	{
		if (dstsize > 1)
		{
			dst[i] = src[i];
			i++;
			dstsize--;
		}
		srclen++;
	}
	if (dstsize)
		dst[i] = '\0';
	return (srclen);
}
