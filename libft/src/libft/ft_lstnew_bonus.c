/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:32:35 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:33:29 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstnew - Creates a new node in the linked list with the given content.

@param content: The data/content to be stored in the new node.

@return: The newly created node (of type t_list).
	 NULL if memory allocation fails.
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
int	main(void)
{
	t_list	*head;

	head = ft_lstnew("42\n");
	head->next = ft_lstnew("Linked Lists\n");

	printf("%s", (char *)head->content);
	printf("%s", (char *)head->next->content);

	free(head->next);
	free(head);

	return (0);
}
*/
