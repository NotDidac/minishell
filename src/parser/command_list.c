/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:59:54 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:09:14 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/command_list.h"
#include "utils/err_exit.h"

#include <stdlib.h>

t_command	*new_command(void)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		err_exit("Parser", "Failed to allocate memory for command");
	cmd->args = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->is_pipe = false;
	cmd->next = NULL;
	return (cmd);
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
