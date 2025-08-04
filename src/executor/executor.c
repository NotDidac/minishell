/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:06:34 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/command_list.h"
#include "colors.h"

#include <stdio.h>

void	executor(t_command *commands)
{
	if (!commands)
	{
		printf("\nNo commands to execute.\n");
		return ;
	}
	printf(BLUE "[Executor] " RESET "Executing commands...\n");
}
