/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 10:33:49 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:09:49 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_LIST_H
# define TOKEN_LIST_H

typedef struct s_token	t_token;

typedef enum e_token_type
{
	TOKEN_WORD,					// Any word not in quotes or a keyword/operator
	TOKEN_STRING,				// Quoted string (single or double)
	TOKEN_PIPE,					// |
	TOKEN_REDIRECT_IN,			// <
	TOKEN_REDIRECT_OUT,			// >
	TOKEN_REDIRECT_APPEND,		// >>
	TOKEN_HEREDOC,				// <<
	TOKEN_INVALID,				// Invalid token (e.g., unmatched quotes)
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	t_token			*next;
}	t_token;

t_token	*new_token(t_token_type type, char *value);
void	add_token(t_token **head, t_token *new_token);

#endif
