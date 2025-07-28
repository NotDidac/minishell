/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 12:46:48 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:11:02 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_lstiter - Iterates over each node in the list and applies the function f
	     to the content of each node.

@param lst: The pointer to the first node in the list.
@param f: The function to apply to the content of each node.
*/

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
