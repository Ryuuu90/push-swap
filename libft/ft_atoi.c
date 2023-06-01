/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 23:19:47 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 03:05:33 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_perror(int error)
{
	if (error == 1)
		return (write(2, "\033[1;31mThere is an imposter!\033[0m\n", 33), exit(1));
	if (error == 2)
	{
		write(2, "\033[1;31mOne of the numbers exceeded the limits.\033[0m\n", 51);
		exit(1);
	}
	if (error == 3)
		return (write(2, "\033[1;31mExtra spaces.\033[0m\n", 26), exit(1));
	if (error == 4)
	{
		write(2, "\033[1;31mIncorrect number of arguments.\033[0m\n", 42);
		exit(1);
	}
	if (error == 5)
	{
		write(2, "\033[1;35mThere is duplicate numbers!\033[0m\n", 39);
		exit(1);
	}
	if (error == 6)
		return (write(2, "\033[1;31mERROR\033[0m\n", 26), exit(1));
}

int	ft_toint(const char *str, int sign, int i)
{
	int	res;
	int	lim;
	int	j;

	j = 0;
	lim = 0;
	res = 0;
	while (str[j])
	{
		if (str[j] == '-' || str[j] == '+')
			j++;
		if (!(str[j] >= '0' && str[j] <= '9'))
			ft_perror(1);
		j++;
	}
	while (str[i])
	{
		lim = res;
		res = res * 10 + str[i] - '0';
		i++;
		if (res / 10 != lim)
			ft_perror(2);
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
		ft_perror(3);
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			ft_perror(1);
	}
	return (ft_toint(str, sign, i));
}
