/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:19:47 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/12 11:56:02 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_error()
{
	ft_putstr_fd("error", 2);
	exit(1);
}
int	ft_toint(const char *str, int sign, int i)
{
	int	res;
	int	lim;
	int j = 0;

	lim = 0;
	res = 0;
	while(str[j])
	{
		if(str[j] == '-' || str[j] == '+')
			j++;
		if(!(str[j] >= '0' && str[j] <= '9'))
			ft_error();
		j++;
	}
	while (str[i])
	{
		lim = res;
		res = res * 10 + str[i] - '0';
		i++;
		if (res / 10 != lim)
		{
			if (sign < 0)
				ft_error();
			if (sign > 0)
				ft_error();
		}
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		ft_error();
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			ft_error();
	}
	return (ft_toint(str, sign, i));
}
