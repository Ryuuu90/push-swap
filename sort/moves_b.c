/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:21:23 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 08:15:40 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->b || !stacks->b->next)
		return ;
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = stacks->b->next;
	stacks->b->next = tmp;
	write(1, "sb\n", 3);
}

void	pb(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->a)
		return ;
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
	write(1, "pb\n", 3);
}

void	rb(t_stack *stacks)
{
	t_link	*prev;

	if (!ft_lstsizep(stacks->b))
		return ;
	prev = ft_lstlastp(stacks->b);
	prev->next = stacks->b;
	stacks->b = stacks->b->next;
	prev->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stacks)
{
	t_link	*tmp;
	t_link	*sec;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	tmp = stacks->b;
	while (tmp->next != NULL)
	{
		sec = tmp;
		tmp = tmp->next;
	}
	sec->next = NULL;
	tmp->next = stacks->b;
	stacks->b = tmp;
	write(1, "rrb\n", 4);
}
