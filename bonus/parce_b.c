/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:21:05 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/31 10:46:38 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	stack_size(t_stack stacks)
{
	int	i;

	i = 0;
	while (stacks.a->next)
	{
		i++;
		stacks.a = stacks.a->next;
	}
	return (i);
}

int	there_is_double(char **arr, int n, int i)
{
	i++;
	while (arr[i])
	{
		if (ft_atoi(arr[i]) == n)
			return (0);
		i++;
	}
	return (1);
}

void	sorted(t_parce *data)
{
	int	sort;
	int	y;

	sort = 0;
	y = 0;
	while (y < data->size - 1)
	{
		if (data->arr[y] < data->arr[y + 1])
			sort++;
		if (sort == data->size - 1)
			exit(0);
		y++;
	}
}

void	parce(char **av, int ac, t_parce *data)
{
	data->i = 1;
	data->size = 0;
	if (ac > 1)
	{
		while (av[data->i])
		{
			data->str = ft_strjoinn(data->str, av[data->i]);
			data->i++;
		}
		data->s = ft_split(data->str, ' ');
		while (data->s[data->size])
			data->size++;
		data->arr = malloc(sizeof(int) * data->size);
		while (data->s[data->j])
		{
			data->arr[data->j] = ft_atoi(data->s[data->j]);
			if (there_is_double(data->s, data->arr[data->j], data->j) == 0)
				ft_perror(5);
			data->j++;
		}
		sorted(data);
	}
	else
		exit(0);
}
