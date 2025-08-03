/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_log.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:49:22 by didguill          #+#    #+#             */
/*   Updated: 2025/08/03 18:53:12 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include "colors.h"
#include <stdio.h>

void	readline_log(const char *line)
{
	if (!ENABLE_LOGS)
		return ;
	printf(BLUE "\n[Readline] " RESET);
	printf("Input: ");
	printf(CYAN "\"%s\"\n\n" RESET, line);
}
