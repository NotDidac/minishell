/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:37:35 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 19:25:39 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_memcpy - Copies 'n' bytes from memory area 'src' to memory area 'dest'.

@param dest: A pointer to the destination memory area where data will be copied.
@param src: A pointer to the source memory area from which data will be copied.
@param n: The number of bytes to copy from 'src' to 'dest'.

@return: A pointer to the destination memory area 'dest'.
         NULL is returned if either 'dest' or 'src' is NULL.
*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[20];
	size_t	n = 5;

	printf("ft_memcpy...\n");
	printf("@param src: %s\n", src);
	printf("@param n: %zu\n", n);

	ft_memcpy(dest, src, n);
	dest[n] = '\0';

	printf("\n@return: %s\n", dest);

	return (0);
}
*/
