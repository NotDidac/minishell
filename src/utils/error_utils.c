/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:42:08 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 01:34:45 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void	arg_check(int argc);
static void	ensure_interactive_mode(void);

void	print_error_exit(char *prefix, char *msg)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if (prefix)
	{
		ft_putstr_fd(prefix, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	perform_startup_checks(int argc)
{
	ensure_interactive_mode();
	arg_check(argc);
}

static void	arg_check(int argc)
{
	if (argc != 1)
		print_error_exit(NULL, "too many arguments");
}

static void	ensure_interactive_mode(void)
{
	if (!isatty(STDIN_FILENO))
		print_error_exit(NULL, "Standard input is not a terminal");
	if (!isatty(STDOUT_FILENO))
		print_error_exit(NULL, "Standard output is not a terminal");
	if (!isatty(STDERR_FILENO))
		print_error_exit(NULL, "Standard error is not a terminal");
}
