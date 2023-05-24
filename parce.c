/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:21:39 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/13 19:53:23 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack stacks)
{
	int i;

	i = 0;
	while(stacks.a->next)
	{
		i++;
		stacks.a = stacks.a->next;
	}
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
	data->arr = malloc(sizeof(int *) * ac);
	data->size = 0;
	if (ac > 1)
	{
		while (av[data->i])
		{
			data->str = ft_strjoinn(data->str, av[data->i]);
			data->s = ft_split(data->str, ' ');
			data->i++;
		}
		while (data->s[data->size])
			data->size++;
		while (data->s[data->j])
		{
			data->arr[data->j] = ft_atoi(data->s[data->j]);
			if (there_is_double(data->s, data->arr[data->j], data->j) == 0)
				ft_error();
			data->j++;
		}
		data->arr[data->size] = '\0';
		sorted(data);
	}
	else
		ft_error();
}
