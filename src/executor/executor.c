/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 20:45:16 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
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
