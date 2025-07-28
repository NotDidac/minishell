/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:52:49 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:15:33 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_putendl_fd - Writes a string followed by a newline to the given fd.

@param s: The string to write.
@param fd: The file descriptor to write to.
*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
