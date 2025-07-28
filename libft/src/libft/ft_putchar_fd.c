/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:41:56 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:12:45 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_putchar_fd - Writes a single character to the given file descriptor.

@param c: The character to write.
@param fd: The file descriptor to write to.
	   1 for standard output, 2 for standard error, etc...
*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
