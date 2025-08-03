/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:38 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 22:19:20 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils/err_exit.h"

#include <stdlib.h>

t_command	*new_command(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		err_exit(NULL, "Parser", "Failed to allocate memory for command");
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

void	append_command(t_command **head, t_command **new_cmd)
{
	t_command	*tmp;

	if (!*head)
		*head = *new_cmd;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *new_cmd;
	}
	*new_cmd = NULL;
}
