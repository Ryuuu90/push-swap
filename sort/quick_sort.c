/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:21:30 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/05 16:40:43 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_b(t_stack *stacks, int max)
{
	t_link	*a;

	a = stacks->b;
	stacks->pos_max = 0;
	while (a)
	{
		if (max != a->num)
			stacks->pos_max++;
		if (max == a->num)
			return (1);
		a = a->next;
	}
	return (0);
}

int	min(t_stack *stacks)
{
	t_link	*a;
	int		tmp;

	a = stacks->a;
	tmp = stacks->a->num;
	stacks->pos_min = 0;
	while (a)
	{
		if (tmp > a->num)
		{
			tmp = a->num;
		}
		a = a->next;
	}
	a = stacks->a;
	while (a->num != tmp)
	{
		stacks->pos_min++;
		a = a->next;
	}
	return (tmp);
}

void	quick_sort(t_parce *data)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	while (i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->arr[i] > data->arr[j])
			{
				tmp = data->arr[i];
				data->arr[i] = data->arr[j];
				data->arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
