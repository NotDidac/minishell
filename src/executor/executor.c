/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 22:10:09 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	execute_command(char *command)
{
	printf("Executing command: %s\n", command);
}

void	executor(t_shell *shell)
{
	int	i;

	if (!shell->commands)
	{
		printf("No commands to execute.\n");
		return ;
	}
	i = 0;
	while (shell->commands[i])
	{
		execute_command(shell->commands[i]);
		i++;
	}
}
