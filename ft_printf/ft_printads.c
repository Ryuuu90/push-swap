/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 04:16:20 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/12 01:31:42 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printads(unsigned long nbr)
{
	int	count;

	count = 2;
	ft_putstr("0x");
	count += ft_lowerhexa_p(nbr);
	return (count);
}
