/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:13 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 16:52:31 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include "token.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

# define PATH_MAX 4096

typedef struct s_shell
{
	char	*prompt;
	char	*input;
	t_token	*tokens;
	char	**commands;

	bool	exit_requested;
}	t_shell;

// init.c
void	init_shell(t_shell *shell);

// readline.c
void	shell_readline(t_shell *shell);

// lexer.c
void	lexer(t_shell *shell);

// parser.c
void	parser(t_shell *shell);

// executor.c
void	executor(t_shell *shell);

// free.c
void	free_shell(t_shell *shell);
void	clear_shell_state(t_shell *shell);

// utils.c
bool	is_operator(char c);
bool	is_quote(char c);

// lexer_utils.c
t_token	*new_token(t_token_type type, char *value);
void	add_token(t_token **head, t_token *new);

// error_utils.c
void	print_error_exit(char *cmd, char *msg);
void	perform_startup_checks(int argc);

#endif
