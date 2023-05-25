/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 04:10:13 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/25 01:02:14 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperhexa(unsigned int n)
{
	char			*str;
	unsigned int	i;
	int				count;

	count = 0;
	i = 0;
	str = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_upperhexa(n / 16);
		count += ft_upperhexa(n % 16);
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
