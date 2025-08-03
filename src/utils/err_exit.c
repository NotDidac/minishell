/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:39:31 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 19:53:42 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "free/free.h"
#include "libft.h"

void	err_exit(t_shell *shell, char *prefix, char *msg)
{
	if (shell)
		free_shell(shell);
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
