/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startup_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:42:08 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 19:58:44 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "utils/err_exit.h"

#include <unistd.h>

static void	arg_check(int argc);
static void	ensure_interactive_mode(void);

void	perform_startup_checks(int argc)
{
	ensure_interactive_mode();
	arg_check(argc);
}

static void	arg_check(int argc)
{
	if (argc != 1)
		err_exit(NULL, NULL, "No arguments expected");
}

static void	ensure_interactive_mode(void)
{
	if (!isatty(STDIN_FILENO))
		err_exit(NULL, NULL, "Standard input is not a terminal");
	if (!isatty(STDOUT_FILENO))
		err_exit(NULL, NULL, "Standard output is not a terminal");
	if (!isatty(STDERR_FILENO))
		err_exit(NULL, NULL, "Standard error is not a terminal");
}
