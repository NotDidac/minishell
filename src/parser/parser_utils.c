/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:38 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 18:25:19 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell.h"

t_command	*new_command(t_shell *shell)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		err_exit(shell, "Parser", "Failed to allocate memory for command");
	cmd->args = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->is_pipe = false;
	cmd->next = NULL;
	return (cmd);
}

bool	parse_pipe(t_token **curr)
{
	if (*curr && (*curr)->type == TOKEN_PIPE)
	{
		*curr = (*curr)->next;
		return (true);
	}
	return (false);
}

void	append_command(t_command **head, t_command **cmd)
{
	t_command	*tmp;

	if (!*head)
		*head = *cmd;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *cmd;
	}
	*cmd = NULL;
}
