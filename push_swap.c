#include "push_swap.h"

void	stack_a(t_stack *stacks, t_parce *data)
{
	int i = 0;

	stacks->a = NULL;
	stacks->inc = 0;
	stacks->pos_chunk = 0;
	while(i < data->size)
	{
		ft_lstadd_backp(&stacks->a, ft_lstnewp(data->arr[i]));
		i++;
	}
}

int main(int ac,  char **av)
{
	t_parce data;
	t_stack stacks;
	int i = 0;

	parce(av, ac, &data);
	stack_a(&stacks, &data);
	// while(data.arr[i])
	// {
	// 	printf("%d\n", data.arr[i]);
		
	// }
	// if(data.size == 2)
	// 	sa(&stacks);
	// if(data.size == 3)
	// 	sort_three(&stacks);
	// if(data.size == 4 || data.size == 5)
	// 	sort_four_five(&stacks, data.size);
	if(data.size > 5)
		sort_bigger(&stacks, &data);
	while(stacks.a)
	{
		printf("%d\n", stacks.a->num);
		stacks.a = stacks.a->next;
	}
	printf("inc ======== %d\n", stacks.inc);
}
