/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:27:43 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/05 16:56:32 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countstr(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
			i++;
		}
	}
	return (count);
}

static char	**ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free (s);
	return (0);
}

static char	**ft_fillstr(char const *s, char **str, char c)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i != 0)
		{
			str[j] = ft_substr(s, 0, i);
			if (!str[j])
				return (ft_free(str));
			j++;
		}
		s = s + i;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (!s)
		return (NULL);
	count = ft_countstr(s, c);
	str = (char **) malloc (sizeof(char *) * (count + 1));
	if (!str)
		return (NULL);
	return (ft_fillstr(s, str, c));
}
