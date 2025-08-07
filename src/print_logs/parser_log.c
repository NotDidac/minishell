/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:23:50 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 16:41:06 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_logs/print_utils.h"
#include "parser/command_list.h"
#include "config.h"
#include "colors.h"

#include <stdio.h>

static void	print_command_args(t_command *command);
static void	print_redirections(t_command *command);
static void	print_redirections_body(t_redirection *redir);

void	parser_log(t_command *commands)
{
	t_command		*command;
	int				num_commands;

	num_commands = 1;
	command = commands;
	if (!ENABLE_LOGS)
		return ;
	printf(BLUE "[Parser] " RESET "Parsed Command List:\n\n");
	while (command)
	{
		printf(CYAN "================= Command #%d =================\n\n" RESET,
			num_commands++);
		print_command_args(command);
		print_redirections(command);
		printf("\n\n");
		command = command->next;
	}
}

static void	print_command_args(t_command *command)
{
	size_t	i;

	printf(YELLOW "Command arguments:\n" RESET);
	if (command->args)
	{
		i = 0;
		while (command->args[i])
		{
			printf("  - %s\n", command->args[i]);
			i++;
		}
	}
	else
		printf("  (no arguments)\n");
	printf("\n");
}

static void	print_redirections(t_command *command)
{
	t_redirection	*redir;

	printf(YELLOW "Redirections:\n" RESET);
	redir = command->redirs;
	if (!redir)
	{
		printf("  (no redirections)\n");
		return ;
	}
	printf(GRAY "  -----------------------------------------------------\n"
		RESET);
	print_redirections_body(redir);
}

static void	print_redirections_body(t_redirection *redir)
{
	char	*file_display;

	if (!redir)
		return ;
	printf(YELLOW "  | %-16s | %-30s |" RESET "\n",
		"Type", "File/Delimiter");
	printf(GRAY "  -----------------------------------------------------\n"
		RESET);
	while (redir)
	{
		if (redir->file)
			file_display = redir->file;
		else
			file_display = "(null)";
		printf("  | %-16s | %-30s |\n",
			token_type_to_string(redir->type), file_display);
		redir = redir->next;
	}
	printf(GRAY "  -----------------------------------------------------\n"
		RESET);
}
