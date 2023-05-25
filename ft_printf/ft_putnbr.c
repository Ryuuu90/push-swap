/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:53:10 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/25 01:01:48 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long n)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count++;
		ft_putchar('-');
		nb = -nb;
		count += ft_putnbr(nb);
	}
	else if (nb > 9)
	{	
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else if (nb <= 9)
	{
		count += ft_putchar(nb + 48);
	}
	return (count);
}
