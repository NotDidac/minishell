/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 23:02:40 by didguill         ###   ########.fr       */
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
#include "print_logs/parser_log.h"

#include <stddef.h>

static t_command	*parse_tokens(t_token *tokens);
static void	parse_command_arguments(t_command **cmd, t_token **curr);
static void	parse_command_redirections(t_command **cmd, t_token **curr);

t_command	*parser(t_token *tokens)
{
	t_command	*commands;

	if (!tokens)
		return (NULL);
	commands = parse_tokens(tokens);
	parser_log(commands);
	return (commands);
}

static t_command	*parse_tokens(t_token *tokens)
{
	t_command	*head;
	t_command	*cmd;
	t_token		*curr;
	bool		is_pipe;

	head = NULL;
	cmd = NULL;
	curr = tokens;
	while (curr)
	{
		if (!cmd)
			cmd = new_command();
		parse_command_arguments(&cmd, &curr);
		parse_command_redirections(&cmd, &curr);
		is_pipe = parse_pipe(&curr);
		cmd->is_pipe = is_pipe;
		append_command(&head, &cmd);
		if (!is_pipe)
			break ;
	}
	return (head);
}

// Gather all arguments (TOKEN_WORD, TOKEN_STRING) for the current command
static void	parse_command_arguments(t_command **cmd, t_token **curr)
{
	(void)cmd;
	if (*curr && ((*curr)->type == TOKEN_WORD || (*curr)->type == TOKEN_STRING))
	{
		// Here you would typically add the argument to cmd->args
		*curr = (*curr)->next;
	}
}

// Check for redirection tokens '<' '<<' '>' '>>' and set input/output files accordingly
static void	parse_command_redirections(t_command **cmd, t_token **curr)
{
	(void)cmd;
	while (*curr && ((*curr)->type == TOKEN_REDIRECT_IN ||
			(*curr)->type == TOKEN_REDIRECT_OUT ||
			(*curr)->type == TOKEN_REDIRECT_APPEND ||
			(*curr)->type == TOKEN_HEREDOC))
	{
		// Here you would typically set the input/output files in cmd
		*curr = (*curr)->next;
		if (*curr)
			*curr = (*curr)->next;
	}

}
