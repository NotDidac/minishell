/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/07/29 23:31:30 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void parser(t_shell *shell)
{
	int i;

	if (!shell->tokens)
	{
		shell->commands = NULL;
		return ;
	}
	i = 0;
	while (shell->tokens[i])
		i++;
	shell->commands = malloc(sizeof(char *) * (i + 1));
	if (!shell->commands)
		print_error_exit("parser", "Failed to allocate memory for commands");
	i = 0;
	while (shell->tokens[i])
	{
		shell->commands[i] = ft_strdup(shell->tokens[i]);
		if (!shell->commands[i])
			print_error_exit("parser", "Failed to duplicate token");
		i++;
	}
	shell->commands[i] = NULL;
}
