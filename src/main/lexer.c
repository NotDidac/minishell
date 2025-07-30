/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:10:59 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 16:08:19 by didguill         ###   ########.fr       */
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

#include "shell.h"

static int handle_operator(const char *input, int i, t_token **tokens);
static int handle_quote(const char *input, int i, t_token **tokens);
static int handle_word(const char *input, int i, t_token **tokens);

void	lexer(t_shell *shell)
{
	int		i;
	int		result;
	char	*input;
	t_token	*tokens;

	input = shell->input;
	tokens = NULL;
	if (!input)
	{
		shell->tokens = NULL;
		return ;
	}
	i = 0;
	while (input[i])
	{
		if (is_whitespace(input[i]))
			i++;
		else if (is_operator(input[i]))
			i = handle_operator(input, i, &tokens) + 1;
		else if (is_quote(input[i]))
		{
			result = handle_quote(input, i, &tokens);
			if (result == -1)
			{
				shell->tokens = NULL;
				return ;
			}
			i = result + 1;
		}
		else
			i = handle_word(input, i, &tokens) + 1;
	}
	shell->tokens = tokens;
}

static int handle_operator(const char *input, int i, t_token **tokens)
{
	if (input[i] == '|')
		add_token(tokens, new_token(TOKEN_PIPE, ft_strdup("|")));
	else if (input[i] == '<' && input[i + 1] == '<')
	{
		add_token(tokens, new_token(TOKEN_HEREDOC, ft_strdup("<<")));
		return (i + 1);
	}
	else if (input[i] == '>' && input[i + 1] == '>')
	{
		add_token(tokens, new_token(TOKEN_REDIRECT_APPEND, ft_strdup(">>")));
		return (i + 1);
	}
	else if (input[i] == '<')
		add_token(tokens, new_token(TOKEN_REDIRECT_IN, ft_strdup("<")));
	else if (input[i] == '>')
		add_token(tokens, new_token(TOKEN_REDIRECT_OUT, ft_strdup(">")));
	return (i);
}
static int handle_quote(const char *input, int i, t_token **tokens)
{
	char	*content;
	char	quote;
	int		start;

	quote = input[i++];
	start = i;
	while (input[i] && input[i] != quote)
		i++;
	if (!input[i])
		print_error_exit("lexer", "Unclosed quote");
	content = ft_strndup(&input[start], i - start);
	add_token(tokens, new_token(TOKEN_STRING, content));
	return (i);
}

static int handle_word(const char *input, int i, t_token **tokens)
{
	int		start;
	char	*word;

	start = i;
	while (input[i] && !is_whitespace(input[i]) && !is_operator(input[i])
		&& !is_quote(input[i]))
		i++;
	word = ft_strndup(&input[start], i - start);
	if (!word)
		print_error_exit("lexer", "Failed to allocate memory for word token");
	add_token(tokens, new_token(TOKEN_WORD, word));
	return (i - 1);
}
