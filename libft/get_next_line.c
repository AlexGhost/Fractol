/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acourtin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:04:13 by acourtin          #+#    #+#             */
/*   Updated: 2017/12/11 16:07:34 by acourtin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		remalloc(char **save)
{
	char *tmp;

	tmp = ft_strdup(*save);
	ft_strdel(save);
	if (!(*save = ft_strnew(ft_strlen(tmp) + BUFF_SIZE)))
		return (0);
	*save = ft_strcpy(*save, tmp);
	ft_strdel(&tmp);
	return (1);
}

static int		process(char **save, char **line)
{
	unsigned long long int	i;
	int						write;

	i = 0;
	write = 0;
	ft_strdel(line);
	*line = ft_strdup(*save);
	ft_strdel(save);
	if ((*line)[0] == '\0')
		return (0);
	while ((*line)[i])
	{
		if ((*line)[i] == '\n')
		{
			(*line)[i] = '\0';
			*save = ft_strdup((*line) + i + 1);
			break ;
		}
		i++;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*save[4866];
	int			b;

	if (fd < 0)
		return (-1);
	if (!line || (!save[fd] && !(save[fd] = ft_strnew(BUFF_SIZE))) \
			|| !(*line = ft_strnew(BUFF_SIZE)) || BUFF_SIZE <= 0)
		return (-1);
	while ((b = read(fd, *line, BUFF_SIZE)) != 0)
	{
		if (b < 0)
			return (-1);
		if (remalloc(&save[fd]) == 0)
			return (-1);
		save[fd] = ft_strncat(save[fd], *line, b);
		if (ft_memchr(save, '\n', BUFF_SIZE))
			break ;
	}
	if (process(&save[fd], line))
		return (1);
	ft_strdel(&save[fd]);
	return (0);
}
