/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:26:40 by rrask             #+#    #+#             */
/*   Updated: 2022/12/06 16:24:27 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	mult;

	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	mult = count * size;
	if (mult / count != size)
		return (NULL);
	ptr = malloc(mult);
	if (!ptr)
		return (0);
	ft_bzero(ptr, mult);
	return (ptr);
}
