/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:00:07 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 13:09:20 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_logs/print_utils.h"
#include "lexer/token_list.h"
#include "colors.h"
#include "config.h"
#include <stdio.h>

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
