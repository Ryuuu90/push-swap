/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 04:14:11 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/05 17:10:24 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*sb;

	i = 0;
	if (!s)
		return (NULL);
	if (len >= ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sb = (char *) malloc (len * sizeof(char) + 1);
	if (!sb)
		return (NULL);
	while (s[start] && i < len)
	{
		sb[i] = s[start];
		i++;
		start++;
	}
	sb[i] = '\0';
	return (sb);
}
