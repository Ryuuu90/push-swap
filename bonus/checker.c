/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:16:06 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/09 16:02:56 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	stack_a(t_stack *stacks, t_parse *data)
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
	if (!a)
		return (0);
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

void	checker(char *str, t_stack *stacks)
{
	if (ft_strncmp("sa\n", str, 3) == 0)
		sa_b(stacks);
	else if (ft_strncmp("sb\n", str, 3) == 0)
		sb_b(stacks);
	else if (ft_strncmp("pa\n", str, 3) == 0)
		pa_b(stacks);
	else if (ft_strncmp("pb\n", str, 3) == 0)
		pb_b(stacks);
	else if (ft_strncmp("ra\n", str, 3) == 0)
		ra_b(stacks);
	else if (ft_strncmp("rb\n", str, 3) == 0)
		rb_b(stacks);
	else if (ft_strncmp("rra\n", str, 4) == 0)
		rra_b(stacks);
	else if (ft_strncmp("rrb\n", str, 4) == 0)
		rrb_b(stacks);
	else if (ft_strncmp("rrr\n", str, 4) == 0)
		rrr_b(stacks);
	else if (ft_strncmp("rr\n", str, 3) == 0)
		rr_b(stacks);
	else if (ft_strncmp("ss\n", str, 4) == 0)
		ss_b(stacks);
	else
		ft_perror(6);
}

int	main(int ac, char **av)
{
	t_parse	data;
	t_parse	data2;
	t_stack	stacks;
	char	*line;

	line = NULL;
	data2.str = NULL;
	parse(av, ac, &data);
	stack_a(&stacks, &data);
	line = get_next_line(0);
	while (line)
	{
		checker(line, &stacks);
		free(line);
		line = get_next_line(0);
	}
	if (check_if_sorted(&stacks) == 1 && !ft_lstsizep(stacks.b)
		&& ft_lstsizep(stacks.a) == data.size)
		write(1, "\033[1;32mOK\033[0m\n", 14);
	else
		write(1, "\033[1;31mKO\033[0m\n", 14);
}
