/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:57:40 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 23:02:14 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

static void	update_prompt(t_shell *shell);

void	shell_readline(t_shell *shell)
{
	char	*line;

	update_prompt(shell);
	line = readline(shell->prompt);
	if (!line)
	{
		shell->exit_requested = true;
		shell->input = NULL;
		return ;
	}
	if (*line != '\0')
		add_history(line);
	else
	{
		free(line);
		shell->input = NULL;
		return ;
	}
	readline_log(line);
	shell->input = line;
}

static void	update_prompt(t_shell *shell)
{
	char	*new_prompt;
	char	*tmp;
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		tmp = ft_strjoin("[", cwd);
		if (!tmp)
			err_exit(shell, "utils", "Failed to allocate memory for prompt");
		new_prompt = ft_strjoin(tmp, "] minishell> ");
		free(tmp);
		if (!new_prompt)
			err_exit(shell, "utils", "Failed to allocate memory for prompt");
	}
	else
	{
		new_prompt = ft_strdup("minishell> ");
		if (!new_prompt)
			err_exit(shell, "utils", "Failed to allocate memory for prompt");
	}
	if (shell->prompt)
		free(shell->prompt);
	shell->prompt = new_prompt;
}
