/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:29:32 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 13:02:22 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/command_list.h"
#include <stdlib.h>

static void	free_args(char **args);
static void	clear_redirections(t_redirection *redirs);

void	clear_commands(t_command *command)
{
	t_command	*temp;

	while (command)
	{
		temp = command->next;
		free_args(command->args);
		clear_redirections(command->redirs);
		free(command);
		command = temp;
	}
}

static void	free_args(char **args)
{
	size_t	i;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static void	clear_redirections(t_redirection *redirs)
{
	t_redirection	*temp;

	while (redirs)
	{
		temp = redirs->next;
		free(redirs->file);
		free(redirs);
		redirs = temp;
	}
}
