/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:42:50 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 20:21:22 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	lexer_init(t_shell *shell, char **input, t_token **tokens)
{
	*input = shell->input;
	*tokens = NULL;
	if (!*input)
	{
		shell->tokens = NULL;
		return (0);
	}
	return (1);
}

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

void	add_token(t_token **head, t_token *new)
{
	t_token	*cur;

	if (!new)
		err_exit(NULL, "lexer", "Attempted to add a NULL token");
	if (!*head)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
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
