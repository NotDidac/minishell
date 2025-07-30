/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 22:10:54 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser(t_shell *shell)
{
	t_token	*token;

	if (!shell->tokens)
	{
		printf("No tokens to parse.\n");
		shell->commands = NULL;
		return ;
	}
	printf("Parsing tokens...\n\n");
	token = shell->tokens;
	while (token)
	{
		printf("Token: %-15s Type: %d\n", token->value, token->type);
		token = token->next;
	}
}
