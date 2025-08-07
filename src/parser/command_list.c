/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:59:54 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 10:40:43 by didguill         ###   ########.fr       */
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
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	append_command(t_command **head, t_command *new_cmd)
{
	t_command	*temp;

	if (!head || !new_cmd)
		return ;
	if (*head == NULL)
	{
		*head = new_cmd;
		return ;
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_cmd;
}

t_redirection	*new_redirection(t_token_type type, const char *file)
{
	t_redirection	*redir;

	redir = malloc(sizeof(t_redirection));
	if (!redir)
		err_exit("Parser", "Failed to allocate memory for redirection");
	redir->type = type;
	if (file)
		redir->file = ft_strdup(file);
	else
		redir->file = NULL;
	redir->next = NULL;
	return (redir);
}


void	append_redirection(t_redirection **head, t_redirection *new_redir)
{
	t_redirection	*temp;

	if (!head || !new_redir)
		return ;
	if (*head == NULL)
	{
		*head = new_redir;
		return ;
	}

	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_redir;
}
