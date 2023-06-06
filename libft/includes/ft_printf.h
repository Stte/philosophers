/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:36:12 by rrask             #+#    #+#             */
/*   Updated: 2023/04/07 11:24:28 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putstr_print(char *s);
int	ft_putchar_print(char c);
int	ft_putnbr_print(int c);
int	handle_s(char *s);
int	handle_c(char c);
int	handle_num(int c);
int	handle_void(void *v);
int	handle_hexsmol(unsigned int i);
int	handle_hexbig(unsigned int i);
int	handle_unsign(unsigned int c);
int	ft_hexsmol(unsigned long long i);
int	ft_hexbig(unsigned long long i);
int	ft_putusnbr(unsigned int c);
int	ft_putvoid(void *v);

#endif
