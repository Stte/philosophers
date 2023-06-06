/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:54:55 by rrask             #+#    #+#             */
/*   Updated: 2022/12/08 22:40:32 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return ((size_t)ft_strlen((char *)src));
	dstlen = ft_strlen(dst);
	srclen = ft_strlen((char *)src);
	if (dstsize < dstlen)
		return (dstsize + srclen);
	while (*(src + i) != '\0' && dstsize > dstlen + 1 + i)
	{
		*(dst + dstlen + i) = *(src + i);
		i++;
	}
	*(dst + dstlen + i) = '\0';
	return (dstlen + srclen);
}
