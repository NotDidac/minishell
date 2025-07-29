/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:13 by didguill          #+#    #+#             */
/*   Updated: 2025/07/29 20:22:42 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

typedef struct s_shell
{
	char	*prompt;
}	t_shell;

// init.c
void	init_shell(t_shell *shell);

// free.c
void	free_shell(t_shell *shell);

// utils.c

// error_utils.c
void	print_error_exit(char *cmd, char *msg);
void	arg_check(int argc, char **argv);

#endif
