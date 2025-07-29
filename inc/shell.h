/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:13 by didguill          #+#    #+#             */
/*   Updated: 2025/07/29 20:04:22 by didguill         ###   ########.fr       */
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
	char	**env;
	char	*prompt;
	int		status;
}	t_shell;

// utils.c

// error_utils.c
void	print_error_exit(char *cmd, char *msg);
void	argc_check(int argc);

#endif
