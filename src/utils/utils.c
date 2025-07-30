/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:00:20 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 16:11:51 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

bool is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

bool is_quote(char c)
{
	return (c == '\'' || c == '"');
}

char *ft_strndup(const char *str, size_t max_len)
{
	char	*dup;
	size_t	len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (max_len < len)
		len = max_len;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, str, len + 1);
	return (dup);
}
