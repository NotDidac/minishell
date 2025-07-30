/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 10:13:19 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 20:55:21 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

typedef enum e_token_type
{
	TOKEN_WORD,					// Any word not in quotes or a keyword/operator
	TOKEN_STRING,				// Quoted string (single or double)
	TOKEN_PIPE,					// |
	TOKEN_REDIRECT_IN,			// <
	TOKEN_REDIRECT_OUT,			// >
	TOKEN_REDIRECT_APPEND,		// >>
	TOKEN_HEREDOC,				// <<
	TOKEN_INVALID				// Invalid token (e.g., unrecognized operator)
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;

#endif
