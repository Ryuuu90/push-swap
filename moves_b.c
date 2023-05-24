#include "push_swap.h"

void	sb(t_stack *stacks)
{
	t_link *tmp;

    tmp = stacks->b;
    stacks->b = stacks->b->next;
    tmp->next = stacks->b->next;
    stacks->b->next = tmp;
     write(1, "sb\n", 3);
     stacks->inc++;
}

void	pb(t_stack *stacks)
{
	if(!stacks->a)
		return;
	t_link *tmp =  stacks->a;
	stacks->a = stacks->a->next;
	tmp->next = stacks->b;
	stacks->b = tmp;
     write(1, "pb\n", 3);
     stacks->inc++;
}

void	rb(t_stack *stacks)
{
	t_link *prev = ft_lstlastp(stacks->b);
	prev->next = stacks->b;
	stacks->b = stacks->b->next;
	prev->next->next = NULL;
    write(1, "rb\n", 3);
    stacks->inc++;
}
void rrb(t_stack *stacks)
{
	t_link	*tmp;
	t_link	*sec;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	tmp = stacks->b;
	while (tmp->next != NULL)
	{
		sec = tmp;
		tmp = tmp->next;
	}
	sec->next = NULL;
	tmp->next = stacks->b;
	stacks->b = tmp;
	write(1, "rrb\n", 4);
    stacks->inc++;
}