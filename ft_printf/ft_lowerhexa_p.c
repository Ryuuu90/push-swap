/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lowerhexa_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:00:16 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/25 01:03:26 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lowerhexa_p(unsigned long n)
{
	char			*str;
	unsigned int	i;
	int				count;

	count = 0;
	i = 0;
	str = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_lowerhexa_p(n / 16);
		count += ft_lowerhexa_p(n % 16);
	}
	else if (n < 16)
	{
		while (str[i] && i != n)
			i++;
		if (i == n)
			count += ft_putchar(str[i]);
	}
	return (count);
}
