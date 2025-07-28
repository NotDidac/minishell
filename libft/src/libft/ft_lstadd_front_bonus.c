/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:17:41 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:32:18 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstadd_front - Adds a new node at the beginning of the list.

@param lst: A pointer to the first node of the list.
@param new: The new node to be added at the front of the list.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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

int	main(void)
{
	t_list	*head = NULL;

	ft_lstadd_front(&head, ft_lstnew("It's like the 0 of an array !\n"));
	ft_lstadd_front(&head, ft_lstnew("the front element. "));
	ft_lstadd_front(&head, ft_lstnew("adds to "));
	ft_lstadd_front(&head, ft_lstnew("This "));

	printf("%s", (char *)head->content);
	printf("%s", (char *)head->next->content);
	printf("%s", (char *)head->next->next->content);
	printf("%s", (char *)head->next->next->next->content);
	deallocate(&head);

	return (0);
}
*/
