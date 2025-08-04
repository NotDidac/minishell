/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:19:00 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 10:37:24 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free/clear_commands.h"
#include "lexer/token_list.h"

#include <stdlib.h>

void	clear_tokens(t_token *tokens)
{
	t_token	*current;
	t_token	*next;

	if (!tokens)
		return ;
	current = tokens;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	tokens = NULL;
}
