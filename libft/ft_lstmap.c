/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgrosven <kgrosven@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:09:57 by kgrosven          #+#    #+#             */
/*   Updated: 2024/02/14 11:09:59 by kgrosven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;
	void	*new_content;

	if (lst == 0)
		return (0);
	newlist = 0;
	while (lst != 0)
	{
		new_content = f(lst->content);
		node = ft_lstnew(new_content);
		if (node == 0)
		{
			free(new_content);
			ft_lstclear(&newlist, del);
			return (0);
		}
		ft_lstadd_back(&newlist, node);
		lst = lst->next;
	}
	return (newlist);
}
