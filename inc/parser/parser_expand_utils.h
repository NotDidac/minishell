/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:29:41 by didguill          #+#    #+#             */
/*   Updated: 2025/12/02 15:32:13 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_EXPAND_UTILS_H
# define PARSER_EXPAND_UTILS_H

# include "lexer/token_list.h"

char	*expand_argument(t_token *token, int last_exit_status);

#endif
