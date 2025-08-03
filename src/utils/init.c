/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:17:30 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 19:59:07 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <stddef.h>

void	init_shell(t_shell *shell)
{
	shell->prompt = NULL;
	shell->input = NULL;
	shell->tokens = NULL;
	shell->commands = NULL;
	shell->exit_requested = false;
}
