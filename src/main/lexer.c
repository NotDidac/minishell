/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:10:59 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 10:48:15 by didguill         ###   ########.fr       */
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
#include "token.h"

// Helper to create a new token
static t_token *new_token(t_token_type type, char *value)
{
	t_token *tok = malloc(sizeof(t_token));
	if (!tok)
		return (NULL);
	tok->type = type;
	tok->value = value;
	tok->next = NULL;
	return (tok);
}

// Append to token list
static void add_token(t_token **head, t_token *new)
{
	if (!*head)
		*head = new;
	else
	{
		t_token *cur = *head;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

static bool is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static bool is_operator_char(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static int handle_operator(const char *input, int i, t_token **tokens)
{
	if (input[i] == '|')
		add_token(tokens, new_token(TOKEN_PIPE, strdup("|")));
	else if (input[i] == '<' && input[i + 1] == '<')
	{
		add_token(tokens, new_token(TOKEN_HEREDOC, strdup("<<")));
		return i + 1;
	}
	else if (input[i] == '>' && input[i + 1] == '>')
	{
		add_token(tokens, new_token(TOKEN_REDIRECT_APPEND, strdup(">>")));
		return i + 1;
	}
	else if (input[i] == '<')
		add_token(tokens, new_token(TOKEN_REDIRECT_IN, strdup("<")));
	else if (input[i] == '>')
		add_token(tokens, new_token(TOKEN_REDIRECT_OUT, strdup(">")));
	return i;
}

static int handle_quote(const char *input, int i, t_token **tokens)
{
	char quote = input[i++];
	int start = i;

	while (input[i] && input[i] != quote)
		i++;
	if (!input[i])
	{
		// Unclosed quote
		fprintf(stderr, "minishell: syntax error: unclosed quote\n");
		return -1;
	}
	char *content = strndup(&input[start], i - start);
	add_token(tokens, new_token(TOKEN_STRING, content));
	return i;
}

static int handle_word(const char *input, int i, t_token **tokens)
{
	int start = i;
	while (input[i] && !is_whitespace(input[i]) && !is_operator_char(input[i]) && input[i] != '\'' && input[i] != '\"')
		i++;
	add_token(tokens, new_token(TOKEN_WORD, strndup(&input[start], i - start)));
	return i - 1;
}

void	lexer(t_shell *shell)
{
	int		i = 0;
	char	*input = shell->input;
	t_token	*tokens = NULL;

	if (!input)
	{
		printf("No input to tokenize.\n");
		shell->tokens = NULL;
		return ;
	}
	while (input[i])
	{
		if (is_whitespace(input[i]))
			i++;
		else if (is_operator_char(input[i]))
			i = handle_operator(input, i, &tokens) + 1;
		else if (input[i] == '\'' || input[i] == '"')
		{
			int result = handle_quote(input, i, &tokens);
			if (result == -1)
			{
				// Handle error (e.g., free tokens if needed)
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

