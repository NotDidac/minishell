/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_log.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:23:50 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:58:14 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "parser/command_list.h"
#include "colors.h"
#include "libft.h"

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
	char	*input_file;
	char	*output_file;
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
			input_file = commands->input_file;
		else
			input_file = "NULL";
		if (commands->output_file)
			output_file = commands->output_file;
		else
			output_file = "NULL";
		printf("| %-3d | %-35s | %-12s | %-12s |\n", i, args, input_file,
			output_file);
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
