/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:17:57 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:07:05 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "parser/command_list.h"

void	    executor(t_command *commands);
t_command *test_echo_hola(void);
t_command *test_echo_wc(void);
t_command *test_ls_wc(void);

#endif
