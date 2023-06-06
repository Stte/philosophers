/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:08:21 by rrask             #+#    #+#             */
/*   Updated: 2023/04/19 14:56:54 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**writeuntilc(const char *s, int c, char **strarr)
{
	int		i;
	char	*begin;
	char	*end;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		begin = (char *)s;
		while (*s && *s != c)
			s++;
		end = (char *)s;
		if (begin != end)
		{
			strarr[i++] = ft_substr(begin, 0, end - begin);
			if (!strarr)
				return (NULL);
		}
	}
	strarr[i] = NULL;
	return (strarr);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**strarr;

	strarr = 0;
	if (!s)
		return (0);
	count = wordcount(s, c);
	strarr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strarr)
		return (NULL);
	writeuntilc(s, c, strarr);
	return (strarr);
}
