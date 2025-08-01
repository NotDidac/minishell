/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:26:13 by didguill          #+#    #+#             */
/*   Updated: 2025/08/01 20:30:14 by didguill         ###   ########.fr       */
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

#include "minishell.h"

static t_command	*parse_tokens(t_shell *shell);

void	parser(t_shell *shell)
{
	if (!shell->tokens)
	{
		shell->commands = NULL;
		return ;
	}
	shell->commands = parse_tokens(shell);
	parser_log(shell->commands);
	clear_commands(shell);
}

static t_command	*parse_tokens(t_shell *shell)
{
	t_command	*cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		err_exit(shell, "parser", "Failed to allocate memory for command");
	cmd->args = malloc(sizeof(char *) * 3);
	if (!cmd->args)
		err_exit(shell, "parser", "Failed to allocate memory for command args");
	cmd->args[0] = ft_strdup("ls");
	if (!cmd->args[0])
		err_exit(shell, "parser", "Failed to allocate memory for command arg");
	cmd->args[1] = ft_strdup("-la");
	if (!cmd->args[1])
		err_exit(shell, "parser", "Failed to allocate memory for command arg");
	cmd->args[2] = NULL;
	cmd->input_file = NULL;
	cmd->output_file = ft_strdup("output.txt");
	if (!cmd->output_file)
		err_exit(shell, "parser", "Failed to allocate memory for output file");
	cmd->is_pipe = true;
	cmd->next = NULL;
	return (cmd);
}
