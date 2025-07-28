/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:07:43 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:45:56 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstlast - Returns the last node of a linked list.

@param lst: The head node of the linked list.
@return: The last node in the linked list.
	  NULL if the list is empty.
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*
void	deallocate(t_list **head)
{
	t_list	*curr;
	t_list	*temp;

	curr = *head;
	while (curr != NULL)
	{
		temp = curr;
		curr = curr->next;
		free(temp);
	}
	*head = NULL;
}

void	ft_lstprint(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr)
	{
		printf("%s\n", (char *)curr->content);
		curr = curr->next;
	}
}

int	main(void)
{
	t_list	*result_last_node;
	t_list	*head = NULL;

	head = ft_lstnew("root");
	head->next = ft_lstnew("Node 1");
	head->next->next = ft_lstnew("Node 2");

	printf("List contents:\n");
	ft_lstprint(head);

	result_last_node = ft_lstlast(head);
	printf("\n@return: %s\n", (char *)result_last_node->content);
	deallocate(&head);

	return (0);
}
*/
