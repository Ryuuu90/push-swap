/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 23:03:52 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 08:13:00 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_moves(int move)
{
	int			flag;
	static int prev;
	static char *moves[8] = {"sa", "sb", "ra", "rb", "rra", "rrb", "pa", "pb"};
	//prev = 0;
	flag = !(1);
	if(prev == 0)
	{
		prev = move;
		return;
	}
	if((prev == 1 && move == 2) || (prev == 2 && move == 1))
		printf("ss\n");
	else if((prev == 3 && move == 4) || (prev == 4 && move == 3))
		printf("rr\n");
	else if((prev == 5 && move == 6 )|| (prev == 6 && move == 5))
		printf("rrr\n");
	else
	{
		printf("%s\n", moves[prev - 1]);
		flag = 1;
	}
	prev = 0;
	if(flag == 1)
		prev = move;
}