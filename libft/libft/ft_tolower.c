/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:38:03 by rrask             #+#    #+#             */
/*   Updated: 2022/12/14 17:56:56 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	size_t	new_c;

	new_c = c;
	if (new_c <= 'A' && new_c >= 'Z')
		return ((int)new_c);
	if (new_c >= 'A' && new_c <= 'Z')
		new_c = new_c + 32;
	return ((int)new_c);
}
