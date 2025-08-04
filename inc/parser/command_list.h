/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:02:10 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:10:01 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_LIST_H
# define COMMAND_LIST_H

# include <stdbool.h>

typedef struct s_command	t_command;

typedef struct s_command
{
	char		**args;
	char		*input_file;
	char		*output_file;
	bool		is_pipe;
	t_command	*next;
}	t_command;

t_command	*new_command(void);
void		append_command(t_command **head, t_command **new_cmd);

#endif
