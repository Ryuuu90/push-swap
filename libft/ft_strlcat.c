/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:42:19 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/03 04:20:50 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	size_t	dl;
	size_t	sl;

	i = 0;
	if ((!dst) && dstsize == 0)
		return (ft_strlen(src));
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	j = dl + sl;
	if (dstsize == 0)
		j = sl;
	while (src[i] != '\0' && dl < dstsize - 1 && dstsize != 0)
	{
		dst[dl] = src[i];
		dl++;
		i++;
	}
	dst[dl] = '\0';
	if (dstsize < dl)
		j = sl + dstsize;
	return (j);
}
