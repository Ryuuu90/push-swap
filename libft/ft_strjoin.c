/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:05:32 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 01:48:01 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinn(char *s1, char const *s2)
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
	sj = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (sj == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		sj[i] = s1[i];
		i++;
	}
	sj[i] = ' ';
	i++;
	while (s2[j] != '\0')
		sj[i++] = s2[j++];
	sj[i] = '\0';
	free(s1);
	return (sj);
}
