/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:56:02 by rrask             #+#    #+#             */
/*   Updated: 2023/01/11 12:11:53 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(void *s)
{
	int	pr_len;

	pr_len = 0;
	pr_len += write(1, "0x", 2);
	pr_len += ft_hexsmol((unsigned long long)s);
	return (pr_len);
}
