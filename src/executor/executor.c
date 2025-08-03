/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 18:26:11 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell.h"

void	executor(t_shell *shell)
{
	if (!shell->commands)
	{
		printf("\nNo commands to execute.\n");
		return ;
	}
	printf(BLUE "[Executor] " RESET "Executing commands...\n");
}
