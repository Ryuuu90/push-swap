/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 00:35:54 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/24 23:38:10 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowerhexa(unsigned int n)
{
	char			*str;
	unsigned int	i;
	int				count;

	count = 0;
	i = 0;
	str = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_lowerhexa(n / 16);
		count += ft_lowerhexa(n % 16);
	}
	else if (n < 16)
	{
		while (str[i] && i != n)
			i++;
		if (i == n)
		{
			count += ft_putchar(str[i]);
		}
	}
	return (count);
}
