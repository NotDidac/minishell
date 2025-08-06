/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:57:40 by didguill          #+#    #+#             */
/*   Updated: 2025/08/06 16:29:50 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "config.h"
#include "utils/err_exit.h"
#include "print_logs/readline_log.h"

#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

static char	*get_prompt(void);
static void	sigint_handler(int signum);

char	*read_user_input(void)
{
	char	*line;
	char	*prompt;

	prompt = get_prompt();
	if (!prompt)
		err_exit("utils", "Failed to allocate memory for prompt");
	line = readline(prompt);
	free(prompt);
	if (!line || !*line)
	{
		free(line);
		return (NULL);
	}
	add_history(line);
	readline_log(line);
	return (line);
}

static char	*get_prompt(void)
{
	char	*new_prompt;
	char	*tmp;
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		tmp = ft_strjoin("[", cwd);
		if (!tmp)
			err_exit("utils", "Failed to allocate memory for prompt");
		new_prompt = ft_strjoin(tmp, "] minishell> ");
		free(tmp);
		if (!new_prompt)
			err_exit("utils", "Failed to allocate memory for prompt");
	}
	else
	{
		new_prompt = ft_strdup("minishell> ");
		if (!new_prompt)
			err_exit("utils", "Failed to allocate memory for prompt");
	}
	return (new_prompt);
}

void	setup_line_reader(void)
{
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}

static void	sigint_handler(int signum)
{
	(void)signum;
	write (STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}
