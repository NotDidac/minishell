/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:02:10 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 16:25:44 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LIST_H
# define COMMAND_LIST_H

# include "lexer/token_list.h"

# include <stdbool.h>

typedef struct s_command		t_command;
typedef struct s_redirection	t_redirection;

typedef struct s_redirection
{
	t_token_type	type;	// Type of redirection (e.g., input, output, append)
	char			*file;	// Target filename or heredoc delimiter
	t_redirection	*next;	// Pointer to the next redirection in the list
}	t_redirection;

typedef struct s_command
{
	char			**args;		// Command + args array (argv)
	t_redirection	*redirs;	// Linked list of all redirections for this cmd
	bool			is_valid;	// Flag to indicate if the command is valid
	t_command		*next;		// Pointer to the next command in the list
}	t_command;

t_command		*new_command(void);
void			append_command(t_command **head, t_command *new_cmd);
t_redirection	*new_redirection(t_token_type type, const char *file);
void			append_redirection(t_redirection **head,
					t_redirection *new_redir);

#endif
