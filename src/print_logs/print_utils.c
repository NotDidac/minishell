/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 13:07:08 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 13:07:45 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/token_list.h"

const char	*token_type_to_string(t_token_type type)
{
	if (type == TOKEN_WORD)
		return ("WORD");
	else if (type == TOKEN_STRING)
		return ("STRING");
	else if (type == TOKEN_PIPE)
		return ("PIPE");
	else if (type == TOKEN_REDIRECT_IN)
		return ("REDIRECT_IN");
	else if (type == TOKEN_REDIRECT_OUT)
		return ("REDIRECT_OUT");
	else if (type == TOKEN_REDIRECT_APPEND)
		return ("REDIRECT_APPEND");
	else if (type == TOKEN_HEREDOC)
		return ("HEREDOC");
	else
		return ("INVALID");
}
