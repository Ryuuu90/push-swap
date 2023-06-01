/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:13:11 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/31 10:46:29 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sb_b(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->b || !stacks->b->next)
		return ;
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = stacks->b->next;
	stacks->b->next = tmp;
}

void	pb_b(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->a)
		return ;
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
}

void	rb_b(t_stack *stacks)
{
	t_link	*prev;

	if (!ft_lstsizep(stacks->b))
		return ;
	prev = ft_lstlastp(stacks->b);
	prev->next = stacks->b;
	stacks->b = stacks->b->next;
	prev->next->next = NULL;
}

void	rrb_b(t_stack *stacks)
{
	t_link	*tmp;
	t_link	*sec;

	if (!ft_lstsizep(stacks->b) || !ft_lstsizep(stacks->b->next))
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
}
