/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:53:09 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:15:36 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstmap - Iterates through the list, applying the function f to each element
            of the list. Creates a new list with the results of applying f,
            using the del function to clean up any nodes if allocation fails.

@param lst: The pointer to the first node in the list.
@param f: The function to apply to the content of each node.
@param del: The function to delete the content of a node in case of failure.

@return: A new list.
	 NULL if the allocation fails.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;

	new_head = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}
