/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:57:13 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 19:16:00 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "token.h"
# include "command.h"
# include "colors.h"
# include "shell.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

/* ************************************************************************** */
/*                            FUNCTION DECLARATIONS                           */
/* ************************************************************************** */

void		executor(t_shell *shell);

#endif
