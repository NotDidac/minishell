/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:01:07 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 12:55:56 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "lexer/token_list.h"
# include "parser/command_list.h"

int		is_redirection(t_token_type type);
void	handle_pipe(t_token **tokens, t_command **current_command);
void	append_argument(t_command *command, const char *arg);

#endif
