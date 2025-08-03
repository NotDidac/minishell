/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_handler.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 19:08:16 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 19:08:48 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATOR_HANDLER_H
# define OPERATOR_HANDLER_H

# include "shell.h"
# include "token.h"

int			handle_operator(t_shell *shell, char *input, int i, t_token **tokens);

#endif
