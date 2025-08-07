/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:23:50 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 13:42:40 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_logs/print_utils.h"
#include "parser/command_list.h"
#include "config.h"
#include "colors.h"

#include <stdio.h>

void	parser_log(t_command *commands)
{
	t_command		*cmd;
	t_redirection	*redir;
	int				i;
	int				cmd_index = 1;

	if (!ENABLE_LOGS)
		return ;
	printf(BLUE "[Parser] " RESET "Parsed Command List:\n\n");
	cmd = commands;
	while (cmd)
	{
		// Command header with index and separator
		printf(CYAN "========== Command #%d ==========\n\n" RESET, cmd_index++);

		// Print command arguments
		printf(YELLOW "Command args:\n" RESET);
		if (cmd->args)
		{
			for (i = 0; cmd->args[i]; i++)
				printf("  - %s\n", cmd->args[i]);
		}
		else
		{
			printf("  (no arguments)\n");
		}

		// Print redirections
		printf(YELLOW "Redirections:\n" RESET);
		redir = cmd->redirs;
		if (!redir)
		{
			printf("  (no redirections)\n");
		}
		else
		{
			printf(GRAY "  -----------------------------------------------------\n" RESET);
			printf(YELLOW "  | %-16s | %-30s |" RESET "\n", "Type", "File/Delimiter");
			printf(GRAY "  -----------------------------------------------------\n" RESET);
			while (redir)
			{
				printf("  | %-16s | %-30s |\n",
					token_type_to_string(redir->type),
					redir->file ? redir->file : "(null)");
				redir = redir->next;
			}
			printf(GRAY "  -----------------------------------------------------\n" RESET);
		}
		printf("\n\n");
		cmd = cmd->next;
	}
}


