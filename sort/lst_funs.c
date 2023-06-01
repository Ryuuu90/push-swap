/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_funs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:25:04 by rabou-rk          #+#    #+#             */
/*   Updated: 2023/05/27 11:48:42 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_link	*ft_lstnewp(int num)
{
	t_link	*head;

	head = (t_link *)malloc(sizeof(t_link));
	if (!head)
		return (NULL);
	head->num = num;
	head->next = NULL;
	return (head);
}

int	ft_lstsizep(t_link *stack)
{
	int		count;
	t_link	*a;

	count = 0;
	a = stack;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

t_link	*ft_lstlastp(t_link *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_backp(t_link **lst, t_link *new)
{
	t_link	*node;

	if (new && *lst)
	{
		node = ft_lstlastp(*lst);
		node->next = new;
	}
	else
		*lst = new;
}
