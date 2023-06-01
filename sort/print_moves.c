/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:03:52 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 04:32:01 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_moves(int move)
{
	static int prev;
	static char moves[9][4] = { "no", "sa", "sb", "ra", "rb", "rra", "rrb", "pa", "pb"};
	//prev = 0;
	prev = move;
	if(prev == 0)
	{
		prev = move;
		return;
		//printf("%d +++ %d\n",prev, move);
	}
	if((prev == 1 && move == 2) || (prev == 2 && move == 1))
	{
		printf("ssssssss\n");
		printf("%s\n", "ss");
		prev = 0;
	}
	if((prev == 3 && move == 4) || (prev == 4 && move == 3))
	{
		printf("r1111111\n");
		printf("%s\n", "rr");
		prev = 0;
	}
	if((prev == 5 && move == 6 )|| (prev == 6 && move == 5))
	{
		printf("r22222222\n");
		printf("%s\n", "rrr");
		prev = 0;
	}
	else
	{
		printf("%s\n", moves[prev]);
		printf("zbbbb\n");
		prev = 0;
	}
}