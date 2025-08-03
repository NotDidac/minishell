/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:00:07 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 19:54:00 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "token.h"
#include "colors.h"
#include <stdio.h>

static const char	*token_type_to_string(t_token_type type);

void	lexer_log(t_token *tokens)
{
	t_token		*cur;
	const char	*type;

	if (!ENABLE_LOGS)
		return ;
	printf(BLUE "[Lexer] " RESET "Token List:\n");
	printf(GRAY "-----------------------------------------------\n" RESET);
	printf(YELLOW "| %-16s | %-24s |\n" RESET, "Type", "Value");
	printf(GRAY "-----------------------------------------------\n" RESET);
	cur = tokens;
	while (cur)
	{
		type = token_type_to_string(cur->type);
		printf("| %-16s | %-24s |\n", type, cur->value);
		cur = cur->next;
	}
	printf(GRAY "-----------------------------------------------\n\n" RESET);
}

static const char	*token_type_to_string(t_token_type type)
{
	if (type == TOKEN_WORD)
		return ("WORD");
	else if (type == TOKEN_STRING)
		return ("STRING");
	else if (type == TOKEN_PIPE)
		return ("PIPE");
	else if (type == TOKEN_REDIRECT_IN)
		return ("REDIRECT_IN");
	else if (type == TOKEN_REDIRECT_OUT)
		return ("REDIRECT_OUT");
	else if (type == TOKEN_REDIRECT_APPEND)
		return ("REDIRECT_APPEND");
	else if (type == TOKEN_HEREDOC)
		return ("HEREDOC");
	else
		return ("INVALID");
}
