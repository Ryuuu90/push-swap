/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:12:30 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/25 11:12:21 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchrr(const char *str, int c)
{
	int		i;
	char	*s;

	if (!str)
		return (NULL);
	i = 0;
	s = (char *) str;
	if ((char)c == '\0')
	{
		return (&s[ft_strlen(str)]);
	}
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*sj;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	sj = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (sj == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		sj[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		sj[i++] = s2[j++];
	}
	sj[i] = '\0';
	free(s1);
	return (sj);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s)
		return (NULL);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
