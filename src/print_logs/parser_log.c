/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:23:50 by didguill          #+#    #+#             */
/*   Updated: 2025/08/01 19:59:21 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_header(void);
static void	print_commands(t_command *commands);
static void	build_args_string(t_command *cmd, char *arg_str, size_t size);
static void	print_footer(void);

void	parser_log(t_command *commands)
{
	if (!ENABLE_LOGS)
		return ;
	if (!commands)
	{
		printf(BLUE "[Parser] " RESET "No commands to display.\n\n");
		return ;
	}
	print_header();
	print_commands(commands);
	print_footer();
}

static void	print_header(void)
{
	printf(BLUE "[Parser] " RESET "Command List:\n");
	printf(GRAY "--------------------------------------------------------------"
		"-------------\n" RESET);
	printf(YELLOW "| %-3s | %-35s | %-12s | %-12s |\n" RESET, "#", "Args",
		"Input", "Output");
	printf(GRAY "--------------------------------------------------------------"
		"-------------\n" RESET);
}

static void	print_commands(t_command *commands)
{
	char	*input;
	char	*output;
	char	args[64];
	int		i;

	i = 0;
	while (commands)
	{
		if (commands->args)
			build_args_string(commands, args, sizeof(args));
		else
			ft_strlcpy(args, "NULL", sizeof(args));
		if (commands->input_file)
			input = commands->input_file;
		else
			input = "NULL";
		if (commands->output_file)
			output = commands->output_file;
		else
			output = "NULL";
		printf("| %-3d | %-35s | %-12s | %-12s |\n", i, args, input, output);
		commands = commands->next;
		i++;
	}
}

static void	build_args_string(t_command *cmd, char *arg_str, size_t size)
{
	size_t	len;
	int		j;

	arg_str[0] = '\0';
	len = 0;
	j = 0;
	while (cmd->args && cmd->args[j])
	{
		if (len + ft_strlen(cmd->args[j]) + 1 >= size)
		{
			ft_strlcat(arg_str, "...", size);
			break ;
		}
		if (j > 0)
			ft_strlcat(arg_str, " ", size);
		ft_strlcat(arg_str, cmd->args[j], size);
		len += ft_strlen(cmd->args[j]) + 1;
		j++;
	}
}

static void	print_footer(void)
{
	printf(GRAY "---------------------------------------------------------"
		"------------------\n\n" RESET);
}
