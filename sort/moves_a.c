/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 22:04:44 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 08:15:25 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->a || !stacks->a->next)
		return ;
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->a->next;
	stacks->a->next = tmp;
	write(1, "sa\n", 3);
}

void	pa(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->b)
		return ;
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
	write(1, "pa\n", 3);
}

void	ra(t_stack *stacks)
{
	t_link	*prev;

	if (!ft_lstsizep(stacks->a))
		return ;
	prev = ft_lstlastp(stacks->a);
	prev->next = stacks->a;
	stacks->a = stacks->a->next;
	prev->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_stack *stacks)
{
	t_link	*tmp;
	t_link	*sec;

	if (!stacks->a || !stacks->a->next)
		return ;
	tmp = stacks->a;
	while (tmp->next != NULL)
	{
		sec = tmp;
		tmp = tmp->next;
	}
	sec->next = NULL;
	tmp->next = stacks->a;
	stacks->a = tmp;
	write(1, "rra\n", 4);
}
