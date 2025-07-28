/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:28:27 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:04:04 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstdelone - Deletes a single node from the linked list.

@param lst: The node to delete.
@param del: The function used to delete the content of the node.
*/

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
