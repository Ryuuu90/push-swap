/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:13:59 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/04 04:46:03 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (!lst)
		return ;
	p = *lst;
	while (*lst && p)
	{
		p = p -> next;
		ft_lstdelone(*lst, del);
		*lst = p;
	}
	*lst = NULL;
}
