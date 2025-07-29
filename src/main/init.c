/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:17:30 by didguill          #+#    #+#             */
/*   Updated: 2025/07/29 22:47:41 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	init_shell(t_shell *shell)
{
	shell->prompt = ft_strdup("minishell> ");
	shell->input = NULL;
	shell->tokens = NULL;
	shell->commands = NULL;
	shell->exit_requested = false;
}
