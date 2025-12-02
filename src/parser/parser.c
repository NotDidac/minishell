/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/12/02 14:41:45 by didguill         ###   ########.fr       */
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
#include "parser/parser_expand_utils.h"

#include <stdio.h>
#include <stdlib.h>

static t_command	*parse(t_token *tokens, int last_exit_status);
static void			set_command_arguments(t_token **tokens, t_command *command,
						int last_exit_status);
static void			set_redirections(t_token **tokens, t_command *command);
static void			handle_invalid_command(t_command *command,
						t_token **tokens);

t_command	*parser(t_token *tokens, int last_exit_status)
{
	t_command	*commands;

	if (!tokens)
		return (NULL);
	commands = parse(tokens, last_exit_status);
	clear_tokens(tokens);
	parser_log(commands);
	return (commands);
}

static t_command	*parse(t_token *tokens, int last_exit_status)
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
		set_command_arguments(&tokens, current_command, last_exit_status);
		set_redirections(&tokens, current_command);
		if (!current_command->is_valid)
			handle_invalid_command(current_command, &tokens);
	}
	return (head);
}

static void	set_command_arguments(t_token **tokens, t_command *command,
	int last_exit_status)
{
	t_token	*cur;
	char	*expanded;

	cur = *tokens;
	while (cur && cur->type != TOKEN_PIPE && !is_redirection(cur->type))
	{
		if (cur->type == TOKEN_INVALID)
		{
			command->is_valid = false;
			printf("Invalid token: %s\n", cur->value);
			break ;
		}
		if (cur->type == TOKEN_WORD || cur->type == TOKEN_DQUOTE
			|| cur->type == TOKEN_SQUOTE)
		{
			expanded = expand_argument(cur, last_exit_status);
			append_argument(command, expanded);
			free(expanded);
		}
		cur = cur->next;
	}
	*tokens = cur;
	if (!command->args || !command->args[0])
		command->is_valid = false;
}

static void	set_redirections(t_token **tokens, t_command *command)
{
	t_token			*cur;
	t_token_type	type;
	t_redirection	*new_redir;

	cur = *tokens;
	handle_invalid_command(command, tokens);
	while (cur && is_redirection(cur->type))
	{
		type = cur->type;
		cur = cur->next;
		if (!cur || (cur->type != TOKEN_WORD && cur->type != TOKEN_SQUOTE
				&& cur->type != TOKEN_DQUOTE))
		{
			command->is_valid = false;
			printf("Redirection must be followed by a filename\n");
			return ;
		}
		new_redir = new_redirection(type, cur->value);
		if (!command->redirs)
			command->redirs = new_redir;
		else
			append_redirection(&command->redirs, new_redir);
		cur = cur->next;
	}
	*tokens = cur;
}

static void	handle_invalid_command(t_command *command, t_token **tokens)
{
	t_token	*current_token;

	if (!command || command->is_valid)
		return ;
	current_token = *tokens;
	while (current_token)
		current_token = current_token->next;
	*tokens = current_token;
}
