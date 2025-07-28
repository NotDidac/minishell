/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:39:40 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:09:53 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstclear - Deletes and frees all nodes in the linked list.

@param lst: The address of the pointer to the first node of the list.
@param del: The function used to delete the content of the node.

The pointer to the list must be set to NULL.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*temp;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		temp = curr->next;
		del(curr->content);
		free(curr);
		curr = temp;
	}
	*lst = NULL;
}
