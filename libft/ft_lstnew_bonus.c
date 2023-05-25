/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:44:26 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/03 04:06:57 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*pn;

	pn = (t_list *) malloc (sizeof(t_list));
	if (!pn)
		return (NULL);
	pn -> content = content;
	pn -> next = NULL;
	return (pn);
}
