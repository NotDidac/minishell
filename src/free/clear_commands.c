/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:29:32 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:06:29 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/command_list.h"
#include <stdlib.h>

static void	free_args(char **args);

void	clear_commands(t_command *commands)
{
	t_command	*curr;
	t_command	*next;

	if (!commands)
		return ;
	curr = commands;
	while (curr)
	{
		next = curr->next;
		if (curr->args)
			free_args(curr->args);
		if (curr->input_file)
			free(curr->input_file);
		if (curr->output_file)
			free(curr->output_file);
		free(curr);
		curr = next;
	}
	commands = NULL;
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
