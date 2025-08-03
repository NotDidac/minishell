/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 20:15:57 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 18:25:29 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell.h"

static t_token_type	get_operator_type(char *input);
static int			get_operator_len(t_token_type type);

int	handle_operator(t_shell *shell, char *input, int i,
	t_token **tokens)
{
	t_token			*token;
	t_token_type	type;
	char			*str;
	int				len;

	type = get_operator_type(&input[i]);
	len = get_operator_len(type);
	if (type == TOKEN_INVALID)
		err_exit(shell, "lexer", "Invalid operator");
	str = ft_strndup(&input[i], len);
	if (!str)
		err_exit(shell, "lexer", "Failed to allocate memory for operator");
	token = new_token(type, str);
	if (!token)
	{
		free(str);
		err_exit(shell, "lexer", "Failed to create token for operator");
	}
	add_token(tokens, token);
	return (i + len);
}

static t_token_type	get_operator_type(char *input)
{
	if (input[0] == '|' )
		return (TOKEN_PIPE);
	else if (input[0] == '<')
	{
		if (input[1] && input[1] == '<')
			return (TOKEN_HEREDOC);
		return (TOKEN_REDIRECT_IN);
	}
	else if (input[0] == '>')
	{
		if (input[1] && input[1] == '>')
			return (TOKEN_REDIRECT_APPEND);
		return (TOKEN_REDIRECT_OUT);
	}
	return (TOKEN_INVALID);
}

static int	get_operator_len(t_token_type type)
{
	if (type == TOKEN_HEREDOC || type == TOKEN_REDIRECT_APPEND)
		return (2);
	else if (type == TOKEN_REDIRECT_IN || type == TOKEN_REDIRECT_OUT
		|| type == TOKEN_PIPE)
		return (1);
	return (0);
}
