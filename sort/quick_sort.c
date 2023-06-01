/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:21:30 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/26 07:56:41 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_b(t_stack *stacks)
{
	t_link	*a;
	int		tmp;

	a = stacks->b;
	tmp = stacks->b->num;
	stacks->pos_max = 0;
	while (a)
	{
		if (tmp < a->num)
		{
			tmp = a->num;
		}
		a = a->next;
	}
	a = stacks->b;
	while (a->num != tmp)
	{
		stacks->pos_max++;
		a = a->next;
	}
	return (tmp);
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

int	min_b(t_stack *stacks)
{
	t_link	*a;
	int		tmp;

	a = stacks->b;
	tmp = stacks->b->num;
	while (a)
	{
		if (tmp > a->num)
		{
			tmp = a->num;
		}
		a = a->next;
	}
	return (tmp);
}

int	bmax(t_stack *stacks)
{
	t_stack	*l;
	t_link	*a;
	int		tmp;

	l = stacks;
	a = stacks->b;
	tmp = min_b(stacks);
	while (a)
	{
		if (a->num == max_b(l))
			a = a->next;
		if (tmp < a->num)
		{
			tmp = a->num;
		}
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
