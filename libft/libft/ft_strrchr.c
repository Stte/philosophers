/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:48:28 by rrask             #+#    #+#             */
/*   Updated: 2022/12/12 11:42:35 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	j;

	if (!s && !*s)
		return (NULL);
	j = ft_strlen(s);
	while (j > 0 && s[j] != (unsigned char)c)
		j--;
	if (s[j] != (unsigned char)c)
		return (NULL);
	return ((char *)&s[j]);
}
