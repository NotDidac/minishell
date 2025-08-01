/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:13 by didguill          #+#    #+#             */
/*   Updated: 2025/08/01 20:09:33 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "token.h"
# include "command.h"
# include "colors.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

# define PATH_MAX		4096
# define ENABLE_LOGS	true

typedef struct s_shell
{
	char		*prompt;
	char		*input;
	t_token		*tokens;
	t_command	*commands;

	bool		exit_requested;
}	t_shell;

/* ************************************************************************** */
/*                            FUNCTION DECLARATIONS                           */
/* ************************************************************************** */

void	init_shell(t_shell *shell);
void	free_shell(t_shell *shell);
void	shell_readline(t_shell *shell);
void	lexer(t_shell *shell);
t_token	*new_token(t_token_type type, char *value);
void	add_token(t_token **head, t_token *new);
bool	is_operator(char c);
bool	is_quote(char c);
int		handle_operator(t_shell *shell, char *input, int i, t_token **tokens);
void	parser(t_shell *shell);
void	executor(t_shell *shell);
void	err_exit(t_shell *shell, char *prefix, char *msg);
void	perform_startup_checks(int argc);
void	readline_log(const char *line);
void	lexer_log(t_token *tokens);
void	parser_log(t_command *commands);
void	clear_commands(t_shell *shell);

#endif
