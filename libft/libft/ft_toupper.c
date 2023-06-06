/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:13:53 by rrask             #+#    #+#             */
/*   Updated: 2022/11/20 12:31:07 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	size_t	new_c;

	new_c = c;
	if (new_c <= 'a' && new_c >= 'z')
		return ((int)new_c);
	if (new_c >= 'a' && new_c <= 'z')
		new_c = new_c - 32;
	return ((int)new_c);
}
