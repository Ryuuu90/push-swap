/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:34:12 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/05 16:12:39 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dt;
	unsigned const char	*sc;

	dt = (unsigned char *) dest;
	sc = (unsigned const char *) src;
	if (!dt && !sc)
		return (NULL);
	if (dt > sc)
	{
		while (len != 0)
		{
			dt[len - 1] = sc[len - 1];
			len--;
		}
	}
	else
		ft_memcpy (dt, sc, len);
	return (dest);
}
