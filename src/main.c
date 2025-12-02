/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:49 by didguill          #+#    #+#             */
/*   Updated: 2025/11/27 20:54:52 by didguill         ###   ########.fr       */
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

#include "readline/line_reader.h"
#include "lexer/lexer.h"
#include "parser/parser.h"
#include "executor/executor.h"
#include "utils/err_exit.h"
#include "config.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t	g_signal = 0;

static void	minishell_loop(void);
static void	arg_check(int argc);
static void	ensure_interactive_mode(void);

int	main(int argc, char **envp)
{
	(void)envp;
	arg_check(argc);
	ensure_interactive_mode();
	setup_line_reader();
	minishell_loop();
	return (EXIT_SUCCESS);
}

static void	minishell_loop(void)
{
	t_command	*commands;
	t_token		*tokens;
	char		*user_input;
	int			last_exit_status;

	last_exit_status = 0;
	while (true)
	{
		user_input = read_user_input();
		if (g_signal == SIGINT)
			g_signal = 0;
		if (!user_input)
			break ;
		tokens = lexer(user_input);
		commands = parser(tokens, last_exit_status);
		last_exit_status = executor(commands, last_exit_status);
	}
	rl_clear_history();
}

static void	ensure_interactive_mode(void)
{
	if (!isatty(STDIN_FILENO))
		err_exit(NULL, "Standard input is not a terminal");
	if (!isatty(STDOUT_FILENO))
		err_exit(NULL, "Standard output is not a terminal");
	if (!isatty(STDERR_FILENO))
		err_exit(NULL, "Standard error is not a terminal");
}

static void	arg_check(int argc)
{
	if (argc != 1)
		err_exit(NULL, "No arguments expected");
}
