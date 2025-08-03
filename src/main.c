/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:49 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 22:26:45 by didguill         ###   ########.fr       */
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

#include "shell.h"
#include "readline.h"
#include "utils/init.h"
#include "utils/startup_checks.h"
#include "parser/parser.h"
#include "lexer/lexer.h"
#include "free/free.h"
#include "executor/executor.h"

#include <stdlib.h>

int	g_signal = 0;

static void	minishell_loop(t_shell *shell)
{
	t_command	*commands;
	t_token		*tokens;
	char		*input;

	while (!shell->exit_requested)
	{
		input = shell_readline(shell);
		(void)input;
		tokens = lexer(shell);
		commands = parser(tokens);
		executor(commands);
		free_shell(shell);
	}
}

int	main(int argc, char **envp)
{
	t_shell	shell;

	(void)envp;
	perform_startup_checks(argc);
	init_shell(&shell);
	minishell_loop(&shell);
	free_shell(&shell);
	return (EXIT_SUCCESS);
}
