/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:21:15 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/09 17:22:48 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_and_push(t_stack *stacks, t_parse *data)
{
	if (stacks->b->num == data->arr[data->size - 1])
	{
		pa(stacks);
		data->size--;
	}
	else if (stacks->flag == 0 || stacks->b->num > ft_lstlastp(stacks->a)->num)
	{
		pa(stacks);
		ra(stacks);
		stacks->flag++;
	}
	else
	{
		if (stacks->pos_max <= ft_lstsizep(stacks->b) / 2)
			rb(stacks);
		else
			rrb(stacks);
	}
}

void	update_utils(t_sort *utils, t_parse *data)
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

int	check_if(t_stack *stacks, int start, int end, t_parse data)
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
