/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 07:11:26 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 05:42:30 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stacks)
{
	t_link	*a;
	t_link	*a1;
	t_link	*a2;

	a = stacks->a;
	a1 = stacks->a->next;
	a2 = stacks->a->next->next;
	if (a->num < a1->num && a->num < a2->num && a1->num > a2->num)
	{
		rra(stacks);
		sa(stacks);
	}
	if (a->num > a1->num && a->num > a2->num && a1->num < a2->num)
		ra(stacks);
	if (a->num > a1->num && a->num > a2->num && a1->num > a2->num)
	{
		ra(stacks);
		sa(stacks);
	}
	if (a->num > a1->num && a->num < a2->num)
		sa(stacks);
	if (a->num < a1->num && a->num > a2->num)
		rra(stacks);
}

void	sort_four_five(t_stack *stacks, int size)
{
	t_sort	utils;

	utils.loop = size - 4;
	utils.i = 0;
	utils.j = 0;
	while (utils.i <= utils.loop)
	{
		utils.mini = min(stacks);
		while (stacks->a->num != utils.mini
			&& stacks->pos_min <= ft_lstsizep(stacks->a) / 2)
			ra(stacks);
		while (stacks->a->num != utils.mini
			&& stacks->pos_min > ft_lstsizep(stacks->a) / 2)
			rra(stacks);
		if (stacks->a->num == utils.mini)
			pb(stacks);
		sort_three(stacks);
		utils.i++;
	}
	while (utils.j < utils.i)
	{
		pa(stacks);
		utils.j++;
	}
}

void	push_to_b(t_stack *stacks, t_parce *data)
{
	t_sort	utils;

	update_utils(&utils, data);
	while (stacks->a)
	{
		if (check_if(stacks, utils.start, utils.end, *data) == 0)
		{
			utils.start -= utils.offset;
			utils.end += utils.offset;
			if (utils.start < 0)
				utils.start = 0;
			if (utils.end > data->size - 1)
				utils.end = data->size - 1;
		}
		while (!(stacks->a->num >= data->arr[utils.start]
				&& stacks->a->num <= data->arr[utils.end])
			&& stacks->pos_chunk <= ft_lstsizep(stacks->a) / 2)
			ra(stacks);
		while (!(stacks->a->num >= data->arr[utils.start]
				&& stacks->a->num <= data->arr[utils.end])
			&& stacks->pos_chunk > ft_lstsizep(stacks->a) / 2)
			rra(stacks);
		do_pb(stacks, data, utils);
	}
}

void	push_back(t_stack *stacks, t_parce *data)
{
	while (stacks->b)
	{
		stacks->flag = 0;
		max_b(stacks);
		while (stacks->b->num != data->arr[data->size - 1]
			&& stacks->pos_max < ft_lstsizep(stacks->b) / 2)
			do_rb(stacks, data);
		while (stacks->b->num != data->arr[data->size - 1]
			&& stacks->pos_max >= ft_lstsizep(stacks->b) / 2)
			do_rrb(stacks, data);
		do_pa(stacks, data);
	}
}

void	sort_bigger(t_stack *stacks, t_parce *data)
{
	quick_sort(data);
	push_to_b(stacks, data);
	push_back(stacks, data);
}
