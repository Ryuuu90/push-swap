/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 04:46:55 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/12/09 23:19:09 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	linelen(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

char	*read_file(int fd, char *line)
{
	char	*buff;
	int		numread;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	numread = 1;
	while (!ft_strchr(line, '\n') && numread)
	{
		numread = read(fd, buff, BUFFER_SIZE);
		if (numread == -1)
		{
			free (buff);
			free (line);
			return (NULL);
		}
		buff[numread] = '\0';
		line = ft_strjoin(line, buff);
	}
	free (buff);
	return (line);
}

char	*get_first_line(char *line)
{
	char	*str;
	int		j;
	int		lile;

	j = 0;
	if (!ft_strlen(line))
		return (NULL);
	lile = linelen(line);
	if (line[lile] == '\n')
		str = malloc(sizeof(char) * (lile + 2));
	else
		str = malloc(sizeof(char) * (lile + 1));
	if (!str)
		return (NULL);
	while (line[j] && j <= lile)
	{
		str[j] = line[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*read_next_line(char *line)
{
	char	*str;
	int		lile;
	int		i;

	i = 0;
	lile = linelen(line);
	if (!line[lile])
	{
		free(line);
		return (NULL);
	}
	lile++;
	str = malloc(sizeof(char) * (ft_strlen(line) - lile + 1));
	if (!str)
		return (NULL);
	while (line[lile])
		str[i++] = line[lile++];
	str[i] = '\0';
	free (line);
	return (str);
}

char	*get_next_linee(int fd)
{
	static char	*line[512];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 512)
		return (NULL);
	line[fd] = read_file(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	str = get_first_line(line[fd]);
	line[fd] = read_next_line(line[fd]);
	return (str);
}
