/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:21:39 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/06 22:43:46 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sorted(t_parse *data)
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

void	parse(char **av, int ac, t_parse *data)
{
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
		ft_perror(4);
}

void	do_pb(t_stack *stacks, t_parse *data, t_sort utils)
{
	if (stacks->a->num >= data->arr[utils.start]
		&& stacks->a->num <= data->arr[utils.end])
		pb(stacks);
	if (stacks->b->num < data->arr[utils.mid] && stacks->b->next)
		rb(stacks);
	if (ft_lstsizep(stacks->a) == 1)
		pb(stacks);
}
