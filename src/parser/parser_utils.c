/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:38 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:00:51 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/token_list.h"

#include <stdbool.h>

bool	parse_pipe(t_token **curr)
{
	if (*curr && (*curr)->type == TOKEN_PIPE)
	{
		*curr = (*curr)->next;
		return (true);
	}
	return (false);
}
