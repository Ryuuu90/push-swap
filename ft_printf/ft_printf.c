/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 05:15:31 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/24 23:23:28 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_verifi(const char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'x')
		return (ft_lowerhexa(va_arg(args, int)));
	else if (c == 'X')
		return (ft_upperhexa(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printads(va_arg(args, long)));
	else if (c == 'u')
		return (ft_putnbr_un(va_arg(args, int)));
	else if (c == '%')
	{
		len += ft_putchar(c);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_verifi(str[i], args);
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
