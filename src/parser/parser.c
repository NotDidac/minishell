/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/08/07 15:38:53 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*   SYNTAX ANALYZER (PARSER)                                                 */
/*                                                                            */
/*   The parser processes tokens from the lexer and builds a command          */
/*   structure representing the shell input. It checks syntax and organizes   */
/*   commands, pipes, and redirections for execution.                         */
/*                                                                            */
/*    Input:  ["ls", "-la", "|", "grep", ".txt", ">", "output"]               */
/*    Output: Pipeline: Command1("ls -la") | Command2("grep .txt > output")   */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser_utils.h"
#include "parser/command_list.h"
#include "print_logs/parser_log.h"
#include "free/clear_tokens.h"
#include "utils/err_exit.h"

#include <stddef.h>

static t_command	*parse(t_token *tokens);
static void			set_command_arguments(t_token **tokens, t_command *command);
static void			set_redirections(t_token **tokens, t_command *command);

t_command	*parser(t_token *tokens)
{
	t_command	*commands;

	if (!tokens)
		return (NULL);
	commands = parse(tokens);
	clear_tokens(tokens);
	parser_log(commands);
	return (commands);
}

static t_command	*parse(t_token *tokens)
{
	t_command	*head;
	t_command	*current_command;

	head = NULL;
	current_command = NULL;
	while (tokens)
	{
		if (!current_command)
		{
			current_command = new_command();
			append_command(&head, current_command);
		}
		if (tokens->type == TOKEN_PIPE)
		{
			handle_pipe(&tokens, &current_command);
			continue ;
		}
		set_command_arguments(&tokens, current_command);
		set_redirections(&tokens, current_command);
	}
	if (!current_command || !current_command->args || !current_command->args[0])
		err_exit("Parser", "Last command is empty");
	return (head);
}

static void	set_command_arguments(t_token **tokens, t_command *command)
{
	t_token	*current_token;

	current_token = *tokens;
	while (current_token && current_token->type != TOKEN_PIPE
		&& !is_redirection(current_token->type))
	{
		if (current_token->type == TOKEN_WORD
			|| current_token->type == TOKEN_STRING)
			append_argument(command, current_token->value);
		else if (current_token->type == TOKEN_INVALID)
		{
			clear_tokens(*tokens);
			err_exit("Parser", "Invalid token encountered");
		}
		current_token = current_token->next;
	}
	*tokens = current_token;
}

static void	set_redirections(t_token **tokens, t_command *command)
{
	t_token			*current_token;
	t_token_type	type;
	t_redirection	*new_redir;

	current_token = *tokens;
	while (current_token && is_redirection(current_token->type))
	{
		type = current_token->type;
		current_token = current_token->next;
		if (!current_token || (current_token->type != TOKEN_WORD
				&& current_token->type != TOKEN_STRING))
		{
			clear_tokens(*tokens);
			err_exit("Parser", "Redirection must be followed by a filename");
		}
		new_redir = new_redirection(type, current_token->value);
		if (!command->redirs)
			command->redirs = new_redir;
		else
			append_redirection(&command->redirs, new_redir);
		current_token = current_token->next;
	}
	*tokens = current_token;
}
