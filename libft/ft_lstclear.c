/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:09:00 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 11:09:06 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*next;

	if (lst == 0)
		return ;
	node = *lst;
	while (node != 0)
	{
		next = node->next;
		ft_lstdelone(node, del);
		node = next;
	}
	*lst = 0;
}
