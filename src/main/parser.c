/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 10:54:43 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	parser(t_shell *shell)
{
	if (!shell->tokens)
	{
		printf("No tokens to parse.\n");
		shell->commands = NULL;
		return ;
	}
	printf("Parsing tokens...\n\n");
	// For now, just print the tokens
	t_token *token = shell->tokens;
	while (token)
	{
		printf("Token: %-15s Type: %d\n", token->value, token->type);
		token = token->next;
	}
}
