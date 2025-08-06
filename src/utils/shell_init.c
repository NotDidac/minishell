/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 19:42:08 by didguill          #+#    #+#             */
/*   Updated: 2025/08/06 16:09:57 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/signal_handler.h"
#include "utils/err_exit.h"

#include <unistd.h>

static void	arg_check(int argc);
static void	ensure_interactive_mode(void);

void	initialize_shell(int argc)
{
	ensure_interactive_mode();
	arg_check(argc);
	setup_signal_handlers();
}

static void	ensure_interactive_mode(void)
{
	if (!isatty(STDIN_FILENO))
		err_exit(NULL, "Standard input is not a terminal");
	if (!isatty(STDOUT_FILENO))
		err_exit(NULL, "Standard output is not a terminal");
	if (!isatty(STDERR_FILENO))
		err_exit(NULL, "Standard error is not a terminal");
}

static void	arg_check(int argc)
{
	if (argc != 1)
		err_exit(NULL, "No arguments expected");
}
