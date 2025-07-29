/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:49 by didguill          #+#    #+#             */
/*   Updated: 2025/07/29 21:03:53 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	g_signal = 0;

/*
static void	minishell_loop(t_shell *shell)
{
	char	*input;

	while (1)
	{
		input = readline(shell->prompt);
		if (!input)
			handle_ctrl_d(shell);  // Exit cleanly on Ctrl-D

		if (input[0] != '\0')
			add_history(input);

		if (!lexer(shell, input))  // Tokenize input
		{
			free(input);
			continue;
		}
		if (!parser(shell))        // Build command structures
		{
			free_shell(shell, false);
			free(input);
			continue;
		}
		executor(shell);           // Run commands
		free_shell(shell, true);   // Clean command-related memory
		free(input);
	}
} */

int	main(int argc, char **argv)
{
	t_shell	shell;

	arg_check(argc, argv);
	init_shell(&shell);

	/*
	setup_signal_handling();       // Setup SIGINT, SIGQUIT
	minishell_loop(&shell);        // Main shell loop (read, parse, exec)
	*/

	free_shell(&shell);

	return (EXIT_SUCCESS);
}
