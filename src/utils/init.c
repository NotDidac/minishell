/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:17:30 by didguill          #+#    #+#             */
/*   Updated: 2025/07/31 16:26:16 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *shell)
{
	shell->prompt = NULL;
	shell->input = NULL;
	shell->tokens = NULL;
	shell->commands = NULL;
	shell->exit_requested = false;
}
