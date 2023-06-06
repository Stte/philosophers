/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 10:53:03 by rrask             #+#    #+#             */
/*   Updated: 2022/12/14 17:18:48 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	int		start;
	char	*trimmed;

	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1) - 1;
	start = 0;
	while (s1[start] && ft_strchr(set, (int)s1[start]))
		start++;
	while (ft_strchr(set, (int)s1[end]) && end > start)
		end--;
	if (start > end)
		return (ft_strdup(""));
	trimmed = ft_substr(s1, start, end - start + 1);
	return (trimmed);
}
