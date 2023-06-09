/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 22:07:11 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/07 08:04:52 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ss_b(t_stack *stacks)
{
	sa_b(stacks);
	sb_b(stacks);
}

void	rr_b(t_stack *stacks)
{
	ra_b(stacks);
	rb_b(stacks);
}

void	rrr_b(t_stack *stacks)
{
	rra_b(stacks);
	rrb_b(stacks);
}
