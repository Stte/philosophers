/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:26:27 by rrask             #+#    #+#             */
/*   Updated: 2023/05/23 10:34:20 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# define RAS_MAX 2147483647
# define RAS_MIN -2147483648

typedef struct s_list
{
	struct s_list	*next;
	void			*content;
}		t_list;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isdigit(int c);
int		ft_isdigit_neg(int c);
int		ft_isascii(int c);
int		ft_isalnum(size_t c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(const char *str);
int		ft_strlenexclude(const char *str, char c);
int		ft_strchrint(const char *s, int c);
char	*ft_strjoinfree(char const *line, char const *buf);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
t_list	*ft_lstnew(void *content);

#endif