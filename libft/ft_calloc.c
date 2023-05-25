/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:31:06 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/04 04:54:10 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	s = malloc (count * size);
	if (!s)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
