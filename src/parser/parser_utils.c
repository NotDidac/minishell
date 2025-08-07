/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:38 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 12:58:26 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer/token_list.h"
#include "parser/command_list.h"
#include "utils/err_exit.h"
#include "libft.h"

int	is_redirection(t_token_type type)
{
	return (type == TOKEN_REDIRECT_IN
		|| type == TOKEN_REDIRECT_OUT
		|| type == TOKEN_REDIRECT_APPEND
		|| type == TOKEN_HEREDOC);
}

void	handle_pipe(t_token **tokens, t_command **current_command)
{
	t_command	*command;
	t_token		*token;

	command = *current_command;
	token = *tokens;
	if (!command->args || !command->args[0])
		err_exit("Parser", "Empty command before pipe");
	*tokens = token->next;
	*current_command = NULL;
}

void	append_argument(t_command *command, const char *arg)
{
	char	**new_args;
	size_t	i;
	size_t	j;

	i = 0;
	while (command->args && command->args[i])
		i++;

	new_args = malloc(sizeof(char *) * (i + 2));
	if (!new_args)
		err_exit("Parser", "Failed to allocate memory for arguments");
	j = 0;
	while (j < i)
	{
		new_args[j] = command->args[j];
		j++;
	}
	new_args[i] = ft_strdup(arg);
	if (!new_args[i])
		err_exit("Parser", "Failed to duplicate argument string");
	new_args[i + 1] = NULL;
	free(command->args);
	command->args = new_args;
}
