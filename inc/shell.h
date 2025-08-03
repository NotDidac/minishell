/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:23:13 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 18:24:04 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

#include "token.h"
#include "command.h"

typedef struct s_shell
{
	char		*prompt;
	char		*input;
	t_token		*tokens;
	t_command	*commands;

	bool		exit_requested;
}	t_shell;

#endif
