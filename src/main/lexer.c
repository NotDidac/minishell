/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:10:59 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 20:53:30 by didguill         ###   ########.fr       */
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

static void	lexer_process(t_shell *shell, char *input, t_token **tokens);
static int	handle_quote(t_shell *shell, char *input, int i, t_token **tokens);
static int	handle_word(t_shell *shell, char *input, int i, t_token **tokens);

void	lexer(t_shell *shell)
{
	char	*input;
	t_token	*tokens;

	if (!lexer_init(shell, &input, &tokens))
		return ;
	lexer_process(shell, input, &tokens);
	shell->tokens = tokens;
}

static void	lexer_process(t_shell *shell, char *input, t_token **tokens)
{
	int		i;

	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]))
			i++;
		else if (is_operator(input[i]))
			i = handle_operator(shell, input, i, tokens);
		else if (is_quote(input[i]))
			i = handle_quote(shell, input, i, tokens);
		else
			i = handle_word(shell, input, i, tokens);
	}
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
		err_exit(shell, "lexer", "Failed to allocate memory for quoted token");
	token = new_token(TOKEN_STRING, content);
	if (!token)
	{
		free(content);
		err_exit(shell, "lexer", "Failed to create token for quoted string");
	}
	add_token(tokens, token);
	return (i + 1);
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
		err_exit(shell, "lexer", "Failed to allocate memory for word token");
	token = new_token(TOKEN_WORD, word);
	if (!token)
	{
		free(word);
		err_exit(shell, "lexer", "Failed to create token for word");
	}
	add_token(tokens, token);
	return (i);
}
