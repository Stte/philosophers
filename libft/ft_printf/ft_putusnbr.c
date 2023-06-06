/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:09:44 by rrask             #+#    #+#             */
/*   Updated: 2023/01/10 16:13:42 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putusnbr(unsigned int c)
{
	int	pr_len;

	pr_len = 0;
	if (c > 9)
		pr_len += ft_putusnbr(c / 10);
	pr_len += ft_putchar_print(c % 10 + '0');
	return (pr_len);
}
