/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:56:31 by rrask             #+#    #+#             */
/*   Updated: 2022/12/06 16:34:42 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	len;

	if (!s || !*s)
		return ;
	if (!f)
		return ;
	len = 0;
	while (s[len])
	{
		(*f)(len, &s[len]);
		len++;
	}
}
