/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 06:21:26 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/07 08:00:47 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_link
{
	int				num;
	struct s_link	*next;
}					t_link;

typedef struct s_stack
{
	t_link			*a;
	t_link			*b;
	int				pos_min;
	int				pos_max;
	int				pos_chunk;
	int				flag;

}					t_stack;

typedef struct push_swap
{
	char			*str;
	char			**s;
	int				*arr;
	int				i;
	int				j;
	int				size;
}					t_parse;

typedef struct s_sort
{
	int				i;
	int				j;
	int				loop;
	int				mini;
	int				div;
	int				offset;
	int				mid;
	int				start;
	int				end;
}					t_sort;

void				ft_perror(int error);
void				parse(char **av, int ac, t_parse *data);
t_link				*ft_lstnewp(int num);
t_link				*ft_lstlastp(t_link *lst);
void				ft_lstadd_backp(t_link **lst, t_link *new);
void				ft_lstadd_frontp(t_link **lst, t_link *new);
void				sa(t_stack *stacks);
void				pa(t_stack *stacks);
void				ra(t_stack *stacks);
void				rra(t_stack *stacks);
void				sb(t_stack *stacks);
void				pb(t_stack *stacks);
void				rb(t_stack *stacks);
void				rrb(t_stack *stacks);
void				rr(t_stack *stacks);
void				rrr(t_stack *stacks);
void				ss(t_stack *stacks);
void				sort_three(t_stack *stacks);
void				sort_four_five(t_stack *stacks, int size);
int					min(t_stack *stacks);
void				quick_sort(t_parse *data);
void				sort_bigger(t_stack *stacks, t_parse *data);
int					ft_lstsizep(t_link *stack);
int					max(t_stack *stacks, int max);
void				update_utils(t_sort *utils, t_parse *data);
int					check_if(t_stack *stacks, int start, int end, t_parse data);
void				do_pb(t_stack *stacks, t_parse *data, t_sort utils);
void				check_and_push(t_stack *stacks, t_parse *data);

#endif