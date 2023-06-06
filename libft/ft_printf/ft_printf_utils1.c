/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:38:01 by rrask             #+#    #+#             */
/*   Updated: 2023/01/11 12:13:43 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_c(char c)
{
	int	pr_len;

	pr_len = 0;
	write(1, &c, 1);
	pr_len++;
	return (pr_len);
}

int	handle_num(int c)
{
	int	pr_len;

	pr_len = 0;
	pr_len += ft_putnbr_print(c);
	return (pr_len);
}

int	handle_s(char *s)
{
	int	pr_len;

	pr_len = ft_putstr_print(s);
	return (pr_len);
}

int	handle_hexsmol(unsigned int var)
{
	int	pr_len;

	pr_len = ft_hexsmol((unsigned long long)var);
	return (pr_len);
}
