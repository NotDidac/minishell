/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:13 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 19:01:32 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "token.h"
# include "command.h"
# include "colors.h"
# include "shell.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

/* ************************************************************************** */
/*                            FUNCTION DECLARATIONS                           */
/* ************************************************************************** */

void		free_shell(t_shell *shell);
void		lexer(t_shell *shell);
t_token		*new_token(t_token_type type, char *value);
void		add_token(t_token **head, t_token *new);
bool		is_operator(char c);
bool		is_quote(char c);
int			handle_operator(t_shell *shell, char *input, int i, t_token **tokens);
void		executor(t_shell *shell);
void		clear_commands(t_shell *shell);

#endif
