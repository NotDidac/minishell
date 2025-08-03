/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:57:40 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 22:41:54 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "config.h"
#include "shell.h"
#include "utils/err_exit.h"
#include "print_logs/readline_log.h"
#include <readline/readline.h>
#include <readline/history.h>

static char	*update_prompt(void);

char	*shell_readline(void)
{
	char	*line;
	char	*prompt;

	prompt = update_prompt();
	line = readline(prompt);
	if (!line)
		return (NULL);
	if (*line != '\0')
		add_history(line);
	else
	{
		free(line);
		return (NULL);
	}
	readline_log(line);
	return (line);
}

static char	*update_prompt(void)
{
	char	*new_prompt;
	char	*tmp;
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		tmp = ft_strjoin("[", cwd);
		if (!tmp)
			err_exit(NULL, "utils", "Failed to allocate memory for prompt");
		new_prompt = ft_strjoin(tmp, "] minishell> ");
		free(tmp);
		if (!new_prompt)
			err_exit(NULL, "utils", "Failed to allocate memory for prompt");
	}
	else
	{
		new_prompt = ft_strdup("minishell> ");
		if (!new_prompt)
			err_exit(NULL, "utils", "Failed to allocate memory for prompt");
	}
	return (new_prompt);
}
