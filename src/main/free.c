/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:19:00 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 22:10:36 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	clear_tokens(t_shell *shell);
static void	clear_commands(t_shell *shell);
static void	free_input(t_shell *shell);
static void	free_prompt(t_shell *shell);

void	free_shell(t_shell *shell)
{
	clear_tokens(shell);
	clear_commands(shell);
	free_input(shell);
	free_prompt(shell);
}

static void	clear_tokens(t_shell *shell)
{
	t_token	*current;
	t_token	*next;

	if (!shell->tokens)
		return ;
	current = shell->tokens;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		free(current);
		current = next;
	}
	shell->tokens = NULL;
}

static void	clear_commands(t_shell *shell)
{
	char	**tmp;

	if (!shell || !shell->commands)
		return ;
	tmp = shell->commands;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(shell->commands);
	shell->commands = NULL;
}

static void	free_input(t_shell *shell)
{
	if (shell->input)
	{
		free(shell->input);
		shell->input = NULL;
	}
}

static void	free_prompt(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->prompt)
	{
		free(shell->prompt);
		shell->prompt = NULL;
	}
}
