/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:56:45 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:17:01 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_putnbr_fd - Writes an int to the given file descriptor.

@param n: The int to write.
@param fd: The file descriptor to write to.
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			n %= 10;
		}
		ft_putchar_fd(n + '0', fd);
	}
}
