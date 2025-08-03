/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:05:56 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 23:15:14 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

# include "token.h"
# include <stdbool.h>

t_token		*new_token(t_token_type type, char *value);
void		add_token(t_token **head, t_token *new_token);
bool		is_operator(char c);
bool		is_quote(char c);

#endif
