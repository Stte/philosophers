/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:30:11 by rrask             #+#    #+#             */
/*   Updated: 2023/01/11 09:38:28 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_print(int c)
{
	size_t	pr_len;

	pr_len = 0;
	if (c == -2147483648)
	{
		pr_len += write(1, "-2147483648", 11);
		return (pr_len);
	}
	else if (c < 0)
	{
		pr_len += ft_putchar_print('-');
		c = c * -1;
	}
	if (c > 9)
		pr_len += ft_putnbr_print(c / 10);
	pr_len += ft_putchar_print(c % 10 + '0');
	return (pr_len);
}
