/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:46:38 by didguill          #+#    #+#             */
/*   Updated: 2025/12/02 15:47:09 by didguill         ###   ########.fr       */
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
	{
		command->is_valid = false;
		printf("Warning: Empty command before pipe.\n");
	}
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

char	*get_env_value(const char *var)
{
	char	*val;

	val = getenv(var);
	if (val)
		return (ft_strdup(val));
	else
		return (ft_strdup(""));
}

char	*ft_strjoin_char(const char *s, char c)
{
	size_t	len;
	char	*res;
	size_t	i;

	len = ft_strlen(s);
	res = malloc(len + 2);
	if (!res)
		err_exit("Parser", "Failed memory allocation");
	i = 0;
	while (i < len)
	{
		res[i] = s[i];
		i++;
	}
	res[len] = c;
	res[len + 1] = '\0';
	return (res);
}
