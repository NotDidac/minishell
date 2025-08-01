/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:56:15 by didguill          #+#    #+#             */
/*   Updated: 2025/08/01 19:17:11 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

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

#endif
