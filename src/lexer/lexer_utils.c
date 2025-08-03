/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:42:50 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 23:01:40 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/err_exit.h"
#include "token.h"
#include <stdlib.h>
#include <stdbool.h>

t_token	*new_token(t_token_type type, char *value)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return (NULL);
	token->type = type;
	token->value = value;
	token->next = NULL;
	return (token);
}

void	add_token(t_token **head, t_token *new_token)
{
	t_token	*cur;

	if (!new_token)
		err_exit("lexer", "Attempted to add a NULL token");
	if (!*head)
		*head = new_token;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new_token;
	}
}

bool	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

bool	is_quote(char c)
{
	return (c == '\'' || c == '"');
}
