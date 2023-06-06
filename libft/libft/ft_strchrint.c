/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:22:21 by rrask             #+#    #+#             */
/*   Updated: 2023/04/17 09:30:27 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrint(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i] != (unsigned char)c && s[i] != '\0')
		i++;
	if (s[i] != (unsigned char)c)
		return (0);
	return (1);
}
