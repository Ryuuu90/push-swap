/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:35:54 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/01 23:28:01 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int c)
{
	int		len;

	len = 0;
	if (c == 0)
		len++;
	while (c < 0)
	{
		if (len == 0)
			len++;
		c = c / 10;
		len++;
	}
	while (c > 0)
	{
		c = c / 10;
		len++;
	}
	return (len);
}

char	*ft_fill(char *str, int size, long nb)
{
	if (nb == 0)
	{
		str[size] = '0';
		return (str);
	}
	while (str && size >= 0)
	{
		if (nb < 0)
		{
				str[0] = '-';
				nb = -nb;
		}
		if (nb > 0)
		{
				str[size] = nb % 10 + 48;
				nb = nb / 10;
		}
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*str;

	size = ft_numlen(n) - 1;
	str = ft_calloc(size + 2, sizeof(char));
	if (!str)
		return (NULL);
	ft_fill(str, size, n);
	return (str);
}
