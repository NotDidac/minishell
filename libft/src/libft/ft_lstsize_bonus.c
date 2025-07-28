/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:58:31 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:41:10 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstsize - Counts the number of elements in a linked list.

@param lst: The head node of the linked list.
@return: The number of elements in the list.
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	node_count;

	node_count = 0;
	while (lst != NULL)
	{
		node_count++;
		lst = lst->next;
	}
	return (node_count);
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
	int	result_size;
	t_list	*head = NULL;

	head = ft_lstnew("root");
	head->next = ft_lstnew("Node 1");
	head->next->next = ft_lstnew("Node 2");

	printf("List contents:\n");
	ft_lstprint(head);

	result_size = ft_lstsize(head);
	printf("\n@return: %d\n", result_size);
	deallocate(&head);

	return (0);
}
*/
