/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:13:52 by rrask             #+#    #+#             */
/*   Updated: 2023/01/11 12:29:39 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_hexbig(unsigned int var)
{
	int	pr_len;

	pr_len = ft_hexbig((unsigned long long)var);
	return (pr_len);
}

int	handle_unsign(unsigned int c)
{
	int	pr_len;

	pr_len = ft_putusnbr(c);
	return (pr_len);
}

int	handle_void(void *s)
{
	int	pr_len;

	pr_len = ft_putvoid(s);
	return (pr_len);
}
