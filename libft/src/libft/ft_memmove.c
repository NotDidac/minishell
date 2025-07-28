/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 08:29:00 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 19:34:11 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_memmove - Copies 'n' bytes from memory area 'src' to memory area 'dest',
             ensuring correct behavior when the memory areas overlap.

@param dest: A pointer to the destination memory area where data will be copied.
@param src: A pointer to the source memory area from which data will be copied.
@param n: The number of bytes to copy from 'src' to 'dest'.

@return: A pointer to the destination memory area 'dest'.
         If 'dest' and 'src' are the same or 'n' is 0, returns 'dest' unchanged.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr == src_ptr || n == 0)
		return (dest);
	if (dest_ptr < src_ptr)
	{
		i = 0;
		while (i < n)
		{
			dest_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dest_ptr[n] = src_ptr[n];
	}
	return (dest);
}

/*
int	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[20];
	size_t	n = 5;

	printf("ft_memmove...\n");
	printf("@param src: %s\n", src);
	printf("@param n: %zu\n", n);

	ft_memmove(dest, src, n);
	dest[n] = '\0';

	printf("\n@return: %s\n", dest);

	return (0);
}
*/
