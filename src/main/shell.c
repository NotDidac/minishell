/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:49 by didguill          #+#    #+#             */
/*   Updated: 2025/07/29 22:58:13 by didguill         ###   ########.fr       */
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

static void minishell_loop(t_shell *shell)
{
    while (true)
    {
        // 1. Read input (store in shell->input)
        shell_readline(shell);

		// Exit loop if user requests it or input is NULL (ctrl-D)
		if (shell->exit_requested || !shell->input)
			break;

        // 2. Tokenize input into tokens stored in shell
        lexer(shell);

        // 3. Parse tokens into commands stored in shell
        parser(shell);

        // 4. Execute commands
        executor(shell);

        // 5. Clear tokens and commands for next iteration
        clear_shell_state(shell);
    }
}

int	main(int argc, char **argv)
{
	t_shell	shell;

	arg_check(argc, argv);
	init_shell(&shell);
	minishell_loop(&shell);
	free_shell(&shell);

	return (EXIT_SUCCESS);
}
