/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:24:59 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:50:38 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstadd_back - Adds a new node to the end of the list.

@param lst: A pointer to the first node of the list.
@param new: The new node to be added to the end.
*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

/*
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

	ft_lstadd_back(&head, ft_lstnew("Well, this way"));
	ft_lstadd_back(&head, ft_lstnew("of adding nodes"));
	ft_lstadd_back(&head, ft_lstnew("seems"));
	ft_lstadd_back(&head, ft_lstnew("much better"));
	ft_lstprint(head);
	deallocate(&head);

	return (0);
}
*/
