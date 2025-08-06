/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/08/06 16:18:17 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/command_list.h"
#include "free/clear_commands.h"
#include "colors.h"

#include <stdio.h>

void	executor(t_command *commands)
{
	if (!commands)
	{
		printf("\nNo commands to execute.\n");
		return ;
	}
	clear_commands(commands);
	printf(BLUE "[Executor] " RESET "Executing commands...\n");
}
