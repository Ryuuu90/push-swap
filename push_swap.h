#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_link
{
	int			num;
	struct s_link	*next;
}	t_link;

typedef struct s_stack
{
	t_link *a;
	t_link *b;
	int		pos_min;
	int		pos_max;
	int		pos_chunk;
	int		inc;

}	t_stack;

typedef struct push_swap
{
	char *str;
	char **s;
	int *arr;
	int i;
	int j;
	int size;
}	t_parce;

typedef struct s_sort
{
	int i;
	int j;
	int loop;
	int mini;
	int div;
	int	offset;
	int mid;
	int start;
	int end;
} t_sort;



void    print_error(int *arr, int len);
void 	parce(char **av, int ac, t_parce *data);
void 	ft_error();
t_link	*ft_lstnewp(int num);
t_link	*ft_lstlastp(t_link *lst);
void	ft_lstadd_backp(t_link **lst, t_link *new);
void	ft_lstadd_frontp(t_link **lst, t_link *new);
void	sa(t_stack *stacks);
void	pa(t_stack *stacks);
void	ra(t_stack *stacks);
void	rra(t_stack *stacks);
void	sb(t_stack *stacks);
void	pb(t_stack *stacks);
void	rb(t_stack *stacks);
void	rrb(t_stack *stacks);
void	rr(t_stack *stacks);
void    sort_three(t_stack *stacks);
void    sort_four_five(t_stack *stacks, int size);
void    sort_five(t_stack *stacks, int size);
int		min(t_stack *stacks);
void    quick_sort(t_parce *data);
void    sort_bigger(t_stack *stacks, t_parce *data);
int		ft_lstsizep(t_link *stack);
int		max_b(t_stack *stacks);
int		bmax(t_stack *stacks);

#endif