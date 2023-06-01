/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:16:06 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/26 18:50:34 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	check_if_sorted(t_stack *stacks)
{
	t_link	*tmp;
	t_link	*a;

	tmp = NULL;
	a = stacks->a;
	while (a)
	{
		tmp = a->next;
		if (!tmp)
			break ;
		if (a->num > tmp->num)
			return (0);
		a = a->next;
	}
	return (1);
}

void	checker(t_parce data2, t_stack *stacks)
{
	while (data2.s[data2.i])
	{
		if (ft_strncmp(data2.s[data2.i], "sa", 2) == 0)
			sa(stacks);
		else if (ft_strncmp(data2.s[data2.i], "sb", 2) == 0)
			sb(stacks);
		else if (ft_strncmp(data2.s[data2.i], "pa", 2) == 0)
			pa(stacks);
		else if (ft_strncmp(data2.s[data2.i], "pb", 2) == 0)
			pb(stacks);
		else if (ft_strncmp(data2.s[data2.i], "ra", 2) == 0)
			ra(stacks);
		else if (ft_strncmp(data2.s[data2.i], "rb", 2) == 0)
			rb(stacks);
		else if (ft_strncmp(data2.s[data2.i], "rra", 3) == 0)
			rra(stacks);
		else if (ft_strncmp(data2.s[data2.i], "rrb", 3) == 0)
			rrb(stacks);
		else
			ft_perror(6);
		data2.i++;
	}
}

int	main(int ac, char **av)
{
	t_parce	data;
	t_parce	data2;
	t_stack	stacks;
	char	*line;
	int		i;

	line = NULL;
	data2.str = NULL;
	data2.i = 0;
	data.arr = malloc(sizeof(int *) * ac);
	parce(av, ac, &data);
	stack_a(&stacks, &data);
	line = get_next_line(0);
	while (line)
	{
		data2.str = ft_strjoin(data2.str, line);
		free(line);
		line = get_next_line(0);
	}
	data2.s = ft_split(data2.str, '\n');
	checker(data2, &stacks);
	if (check_if_sorted(&stacks) == 1)
		write(1, "\033[1;32mOK\033[0m\n", 14);
	else
		write(1, "\033[1;31mKO\033[0m\n", 14);
}
