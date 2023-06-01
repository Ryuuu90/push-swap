/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:21:33 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/01 11:34:30 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a(t_stack *stacks, t_parce *data)
{
	int	i;

	i = 0;
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->flag = 0;
	stacks->pos_chunk = 0;
	while (i < data->size)
	{
		ft_lstadd_backp(&stacks->a, ft_lstnewp(data->arr[i]));
		i++;
	}
}

void	check_space(char **av)
{
	int x;
	int y;
	int count;
	
	x = 1;
	y = 0;
	count = 0;
	while(av[x])
	{
		y = 0;
		while(av[x][y])
		{
			count = 0;
			while(av[x][y] == ' ')
			{
				count++;
				y++;
			}
			if(count == (int)ft_strlen(av[x]))
				ft_perror(1);
			y++;
		}
		
		x++;
	}
}
int	main(int ac, char **av)
{
	t_parce	data;
	t_stack	stacks;
	
	data.i = 1;
	data.size = 0;
	check_space(av);
	parce(av, ac, &data);
	stack_a(&stacks, &data);
	if (data.size == 2)
		sa(&stacks);
	if (data.size == 3)
		sort_three(&stacks);
	if (data.size == 4 || data.size == 5)
		sort_four_five(&stacks, data.size);
	if (data.size > 5)
		sort_bigger(&stacks, &data);
	while(stacks.a)
	{
		printf("%d\n", stacks.a->num);
		stacks.a = stacks.a->next;
	}
}
