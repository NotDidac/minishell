/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:10:59 by didguill          #+#    #+#             */
/*   Updated: 2025/08/06 15:14:37 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   LEXICAL ANALYZER (LEXER)                                                 */
/*                                                                            */
/*   A lexer breaks down input text into tokens - the smallest meaningful     */
/*   units such as commands, arguments, operators (|, <, >), and special      */
/*   characters. It identifies these tokens based on predefined rules,        */
/*   preparing the input for the parser to understand its structure.          */
/*                                                                            */
/*   Input:  "ls -la | grep .txt > output"                                    */
/*   Output: ["ls", "-la", "|", "grep", ".txt", ">", "output"]                */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print_logs/lexer_log.h"
#include "utils/err_exit.h"
#include "lexer/lexer_utils.h"
#include "lexer/operator_handler.h"

static t_token	*tokenize(char *user_input);
static int		handle_quote(char *user_input, int i, t_token **tokens);
static int		handle_word(char *user_input, int i, t_token **tokens);

t_token	*lexer(char *user_input)
{
	t_token	*tokens;

	if (!user_input)
		return (NULL);
	tokens = tokenize(user_input);
	lexer_log(tokens);
	return (tokens);
}

static t_token	*tokenize(char *user_input)
{
	t_token	*tokens;
	int		i;

	tokens = NULL;
	i = 0;
	while (user_input[i])
	{
		if (ft_isspace(user_input[i]))
			i++;
		else if (is_operator(user_input[i]))
			i = handle_operator(user_input, i, &tokens);
		else if (is_quote(user_input[i]))
			i = handle_quote(user_input, i, &tokens);
		else
			i = handle_word(user_input, i, &tokens);
	}
	free(user_input);
	return (tokens);
}

static int	handle_quote(char *user_input, int i, t_token **tokens)
{
	char	*content;
	char	quote;
	int		str_start;
	t_token	*token;

	quote = user_input[i];
	i++;
	str_start = i;
	while (user_input[i] && user_input[i] != quote)
		i++;
	if (!user_input[i])
		err_exit("lexer", "Unclosed quote");
	content = ft_strndup(&user_input[str_start], i - str_start);
	if (!content)
		err_exit("lexer", "Failed to allocate memory for quoted token");
	token = new_token(TOKEN_STRING, content);
	if (!token)
	{
		free(content);
		err_exit("lexer", "Failed to create token for quoted string");
	}
	add_token(tokens, token);
	return (i + 1);
}

static int	handle_word(char *user_input, int i, t_token **tokens)
{
	int		str_start;
	char	*word;
	t_token	*token;

	str_start = i;
	while (user_input[i] && !ft_isspace(user_input[i])
		&& !is_operator(user_input[i])
		&& !is_quote(user_input[i]))
		i++;
	word = ft_strndup(&user_input[str_start], i - str_start);
	if (!word)
		err_exit("lexer", "Failed to allocate memory for word token");
	token = new_token(TOKEN_WORD, word);
	if (!token)
		err_exit("lexer", "Failed to create token for word");
	add_token(tokens, token);
	return (i);
}
