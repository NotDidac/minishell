/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:45:50 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:14:04 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_putstr_fd - Writes a string to the given file descriptor.

@param s: The string to write.
@param fd: The file descriptor to write to.
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}
