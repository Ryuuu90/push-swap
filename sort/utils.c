/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:21:15 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 09:31:37 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rb(t_stack *stacks, t_parce *data)
{
	if (stacks->b->num == data->arr[data->size - 2])
	{
		pa(stacks);
		ra(stacks);
		data->size--;
	}
	else
		rb(stacks);
}

void	do_rrb(t_stack *stacks, t_parce *data)
{
	if (stacks->b->num == data->arr[data->size - 2])
	{
		pa(stacks);
		ra(stacks);
		data->size--;
	}
	else
		rrb(stacks);
}

void	do_pa(t_stack *stacks, t_parce *data)
{
	if (stacks->b->num > ft_lstlastp(stacks->a)->num)
	{
		if (stacks->flag == 1)
		{
			pa(stacks);
			rra(stacks);
			data->size -= 2;
		}
		else
		{
			pa(stacks);
			data->size--;
		}
	}
}

void	update_utils(t_sort *utils, t_parce *data)
{
	if (data->size < 150)
		utils->div = 5;
	if (data->size >= 150)
		utils->div = 17;
	utils->mid = (data->size / 2) - 1;
	utils->offset = data->size / utils->div;
	if (utils->offset == 0)
	{
		utils->offset = 1;
	}
	utils->start = utils->mid - utils->offset;
	utils->end = utils->mid + utils->offset;
}

int	check_if(t_stack *stacks, int start, int end, t_parce data)
{
	t_link	*a;

	a = stacks->a;
	stacks->pos_chunk = 0;
	while (a->next)
	{
		stacks->pos_chunk++;
		if (a->num >= data.arr[start] && a->num <= data.arr[end])
			return (1);
		a = a->next;
	}
	return (0);
}
