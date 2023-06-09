/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:15:18 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/06/07 08:01:53 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
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

void				ft_perror(int error);
void				parse(char **av, int ac, t_parse *data);
t_link				*ft_lstnewp(int num);
t_link				*ft_lstlastp(t_link *lst);
void				ft_lstadd_backp(t_link **lst, t_link *new);
void				ft_lstadd_frontp(t_link **lst, t_link *new);
void				sa_b(t_stack *stacks);
void				pa_b(t_stack *stacks);
void				ra_b(t_stack *stacks);
void				rra_b(t_stack *stacks);
void				sb_b(t_stack *stacks);
void				pb_b(t_stack *stacks);
void				rb_b(t_stack *stacks);
void				rrb_b(t_stack *stacks);
void				rr_b(t_stack *stacks);
void				rrr_b(t_stack *stacks);
void				ss_b(t_stack *stacks);
int					ft_lstsizep(t_link *stack);

#endif