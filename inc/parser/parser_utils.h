/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:01:07 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 10:36:56 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_UTILS_H
# define PARSER_UTILS_H

# include "command.h"
# include "lexer/token_list.h"

t_command	*new_command(void);
bool		parse_pipe(t_token **curr);
void		append_command(t_command **head, t_command **new_cmd);

#endif
