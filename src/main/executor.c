/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/07/29 23:32:47 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void execute_command(char *command)
{
	// Here you would implement the logic to execute a single command
	// For now, we will just print the command to simulate execution
	printf("Executing command: %s\n", command);
	// In a real shell, you would use execve or similar functions here
}

void executor(t_shell *shell)
{
	int i;

	if (!shell->commands)
		return ;
	i = 0;
	while (shell->commands[i])
	{
		execute_command(shell->commands[i]);
		i++;
	}
}
