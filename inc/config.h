/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:58:27 by didguill          #+#    #+#             */
/*   Updated: 2025/11/27 19:12:58 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdbool.h>
# include <signal.h>

extern volatile sig_atomic_t	g_signal;
# define PATH_MAX		4096
# define ENABLE_LOGS	true

#endif
