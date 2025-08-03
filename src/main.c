/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:49 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 22:51:04 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   Project: Minishell                                                       */
/*   Description: Implementation of a simplified shell in C                   */
/*                                                                            */
/*   Features to implement:                                                   */
/*   - Display a working prompt                                               */
/*   - Maintain command history                                               */
/*   - Search and execute commands via PATH, relative, or absolute path       */
/*   - Use only one global variable (for signal number only)                  */
/*   - Handle quotes: single (') and double (")                               */
/*   - Implement redirections: < > << >>                                      */
/*   - Support pipes (|)                                                      */
/*   - Expand environment variables and $?                                    */
/*   - Handle ctrl-C (new prompt), ctrl-D (exit), ctrl-\ (ignored)            */
/*   - Builtins:                                                              */
/*     • echo [-n]                                                            */
/*     • cd [path]                                                            */
/*     • pwd                                                                  */
/*     • export                                                               */
/*     • unset                                                                */
/*     • env                                                                  */
/*     • exit                                                                 */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"
#include "utils/startup_checks.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "executor/executor.h"
#include "token.h"
#include "command.h"

#include <stdlib.h>

int	g_signal = 0;

static void	minishell_loop(void)
{
	t_command	*commands;
	t_token		*tokens;
	char		*input;

	while (true)
	{
		input = shell_readline();
		tokens = lexer(input);
		commands = parser(tokens);
		executor(commands);
	}
}

int	main(int argc, char **envp)
{
	(void)envp;
	perform_startup_checks(argc);
	minishell_loop();
	return (EXIT_SUCCESS);
}
