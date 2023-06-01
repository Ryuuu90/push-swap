/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:07:11 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 05:45:44 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	rr(t_stack *stacks)
{
	ra(stacks);
	rb(stacks);
}

void	rrr(t_stack *stacks)
{
	rra(stacks);
	rrb(stacks);
}
