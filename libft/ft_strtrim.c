/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:32:05 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/05 17:09:49 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ishere(const char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	while (s1[i] && ft_ishere(set, s1[i]))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && ft_ishere(set, s1[j]))
		j--;
	if (i > j)
	{
		return (ft_calloc(1, sizeof(char)));
		if (!ft_calloc(1, sizeof(char)))
			return (NULL);
	}
	return (ft_substr(s1, i, j - i + 1));
}
