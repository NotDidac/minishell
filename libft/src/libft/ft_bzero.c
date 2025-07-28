/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:46:16 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 19:12:58 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_bzero - Sets the first 'n' bytes of the memory area pointed to by 's' to zero.

@param s: A pointer to the memory area to be set to zero.
@param n: The number of bytes to be set to zero.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
