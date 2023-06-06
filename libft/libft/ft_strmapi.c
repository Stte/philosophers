/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:34:39 by rrask             #+#    #+#             */
/*   Updated: 2022/12/12 12:00:28 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*temp;

	if (!s)
		return (NULL);
	if (!f)
		return ((char *)s);
	i = 0;
	len = ft_strlen(s);
	temp = malloc(sizeof(char) * len + 1);
	if (!temp)
		return (NULL);
	while (len > 0)
	{
		temp[i] = f(i, s[i]);
		i++;
		len--;
	}
	temp[i] = '\0';
	return (temp);
}
