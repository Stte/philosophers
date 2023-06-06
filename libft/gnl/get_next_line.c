/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrask <rrask@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:15:51 by rrask             #+#    #+#             */
/*   Updated: 2023/04/20 17:18:01 by rrask            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_stash(char *buf)
{
	char	*remainder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!buf[i])
	{
		free(buf);
		return (NULL);
	}
	remainder = ft_calloc(ft_strlen(buf) - i + 1, sizeof(char));
	if (!remainder)
		return (NULL);
	i++;
	while (buf[i])
	{
		remainder[j] = buf[i];
		i++;
		j++;
	}
	free(buf);
	return (remainder);
}

char	*get_it(char *read_line)
{
	int		index;
	char	*line;

	index = 0;
	if (!*read_line)
		return (NULL);
	while (read_line[index] && read_line[index] != '\n')
		index++;
	line = ft_calloc(index + 2, sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (read_line[index] && read_line[index] != '\n')
	{
		line[index] = read_line[index];
		index++;
	}
	if (read_line[index] == '\n' && read_line[index])
	{
		line[index] = read_line[index];
		index++;
	}
	return (&*line);
}

char	*read_it(char *buf, int fd)
{
	char	*read_buf;
	int		read_bytes;

	if (!buf)
		buf = ft_calloc(1, sizeof(char));
	read_buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buf || !buf)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, read_buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buf);
			free(read_buf);
			return (NULL);
		}
		read_buf[read_bytes] = '\0';
		buf = ft_strjoinfree(buf, read_buf);
		if (ft_strchrint(buf, '\n'))
			break ;
	}
	free(read_buf);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	buf[fd] = read_it(buf[fd], fd);
	if (buf[fd] == NULL)
		return (NULL);
	line = get_it(buf[fd]);
	buf[fd] = update_stash(buf[fd]);
	return (line);
}
