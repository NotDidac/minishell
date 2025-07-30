/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:10:59 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 18:59:37 by didguill         ###   ########.fr       */
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

static int	handle_operator(t_shell *shell, char *input, int i,
				t_token **tokens);
static int	handle_quote(t_shell *shell, char *input, int i, t_token **tokens);
static int	handle_word(t_shell *shell, char *input, int i, t_token **tokens);

void	lexer(t_shell *shell)
{
	int		i;
	int		end_index;
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
		if (ft_isspace(input[i]))
			i++;
		else if (is_operator(input[i]))
			i = handle_operator(shell, input, i, &tokens) + 1;
		else if (is_quote(input[i]))
		{
			end_index = handle_quote(shell, input, i, &tokens);
			i = end_index + 1;
		}
		else
			i = handle_word(shell, input, i, &tokens);
	}
	shell->tokens = tokens;
}

static int	handle_operator(t_shell *shell, char *input, int i,
	t_token **tokens)
{
	t_token			*token;
	t_token_type	type;
	char			*value;

	value = NULL;
	if (input[i] == '|' && (value = ft_strdup("|")))
		type = TOKEN_PIPE;
	else if (input[i] == '<' && input[i + 1] && input[i + 1] == '<'
		&& (value = ft_strdup("<<")))
	{
		type = TOKEN_HEREDOC;
		i++;
	}
	else if (input[i] == '>' && input[i + 1] && input[i + 1] == '>'
		&& (value = ft_strdup(">>")))
	{
		type = TOKEN_REDIRECT_APPEND;
		i++;
	}
	else if (input[i] == '<' && (value = ft_strdup("<")))
		type = TOKEN_REDIRECT_IN;
	else if (input[i] == '>' && (value = ft_strdup(">")))
		type = TOKEN_REDIRECT_OUT;
	else
		err_exit(shell, "lexer", "Invalid operator");
	if (!value)
		err_exit(shell, "lexer", "Failed to allocate memory for token");
	token = new_token(type, value);
	if (!token)
	{
		free(value);
		err_exit(shell, "lexer", "Memory allocation failed for token");
	}
	add_token(tokens, token);
	return (i);
}

static int	handle_quote(t_shell *shell, char *input, int i, t_token **tokens)
{
	char	*content;
	char	quote;
	int		start;
	t_token	*token;

	quote = input[i++];
	start = i;
	while (input[i] && input[i] != quote)
		i++;
	if (!input[i])
		err_exit(shell, "lexer", "Unclosed quote");
	content = ft_strndup(&input[start], i - start);
	if (!content)
		err_exit(shell, "lexer", "Memory allocation failed for quoted token");
	token = new_token(TOKEN_STRING, content);
	if (!token)
	{
		free(content);
		err_exit(shell, "lexer", "Memory allocation failed for token");
	}
	add_token(tokens, token);
	return (i);
}

static int	handle_word(t_shell *shell, char *input, int i, t_token **tokens)
{
	int		start;
	char	*word;
	t_token	*token;

	start = i;
	while (input[i] && !ft_isspace(input[i]) && !is_operator(input[i])
		&& !is_quote(input[i]))
		i++;
	word = ft_strndup(&input[start], i - start);
	if (!word)
		err_exit(shell, "lexer", "Memory allocation failed for word token");
	token = new_token(TOKEN_WORD, word);
	if (!token)
	{
		free(word);
		err_exit(shell, "lexer", "Memory allocation failed for token");
	}
	add_token(tokens, token);
	return (i);
}
