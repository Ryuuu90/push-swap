/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:13:27 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/31 10:55:42 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa_b(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->a || !stacks->a->next)
		return ;
	tmp = stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->a->next;
	stacks->a->next = tmp;
}

void	pa_b(t_stack *stacks)
{
	t_link	*tmp;

	if (!stacks->b)
		return ;
	tmp = stacks->b;
	stacks->b = stacks->b->next;
	tmp->next = stacks->a;
	stacks->a = tmp;
}

void	ra_b(t_stack *stacks)
{
	t_link	*prev;

	if (!ft_lstsizep(stacks->a))
		return ;
	prev = ft_lstlastp(stacks->a);
	prev->next = stacks->a;
	stacks->a = stacks->a->next;
	prev->next->next = NULL;
}

void	rra_b(t_stack *stacks)
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
}
