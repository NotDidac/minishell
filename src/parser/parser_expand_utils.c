/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/12/02 15:50:30 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser_expand_utils.h"
#include "parser/parser_utils.h"
#include "libft.h"
#include "utils/err_exit.h"

#include <stdlib.h>

static char	*expand_variable(const char *str, int *i, int last_exit_status)
{
	char	*res;
	int		start;
	char	*var;

	if (str[*i] == '?')
	{
		res = ft_itoa(last_exit_status);
		(*i)++;
		return (res);
	}
	if (ft_isalpha(str[*i]) || str[*i] == '_')
	{
		start = *i;
		while (ft_isalnum(str[*i]) || str[*i] == '_')
			(*i)++;
		var = ft_strndup(&str[start], *i - start);
		res = get_env_value(var);
		free(var);
		return (res);
	}
	res = ft_strdup("$");
	(*i)++;
	return (res);
}

static char	*append_variable(char *res, const char *str,
	int *i, int last_exit_status)
{
	char	*var_value;
	char	*tmp;

	var_value = expand_variable(str, i, last_exit_status);
	tmp = ft_strjoin(res, var_value);
	free(res);
	free(var_value);
	if (!tmp)
		err_exit("Parser", "Failed to expand variable");
	return (tmp);
}

char	*expand_token(const char *str, int last_exit_status)
{
	char	*res;
	char	*tmp;
	int		i;

	res = ft_strdup("");
	if (!res)
		err_exit("Parser", "Failed to expand token");
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			res = append_variable(res, str, &i, last_exit_status);
		}
		else
		{
			tmp = ft_strjoin_char(res, str[i]);
			free(res);
			res = tmp;
			i++;
		}
	}
	return (res);
}

char	*expand_argument(t_token *token, int last_exit_status)
{
	char	*expanded;

	if (token->type == TOKEN_WORD || token->type == TOKEN_DQUOTE)
	{
		expanded = expand_token(token->value, last_exit_status);
		return (expanded);
	}
	if (token->type == TOKEN_SQUOTE)
	{
		expanded = ft_strdup(token->value);
		if (!expanded)
			err_exit("Parser", "Failed to expand token");
		return (expanded);
	}
	return (NULL);
}
