/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:12:40 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 20:09:54 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_memchr - Locates the first occurrence of 'c' 
	    in the first 'n' bytes of the memory area 's'.

@param s: A pointer to the memory area to be searched.
@param c: The byte to search for, passed as an integer.
@param n: The number of bytes to search in the memory area.

@return: A pointer to the first occurrence of 'c' in the memory area 's'.
         NULL if the byte is not found within the first 'n' bytes.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	*s = "Hello, world!";
	int	c = 'o';
	size_t	n = 12;
	unsigned char	*result;

	printf("ft_memchr...\n");
	printf("@param s: %s\n", s);
	printf("@param c: %c\n", c);
	printf("@param n: %zu\n", n);

	result = ft_memchr(s, c, n);
        printf("\n@return: %s\n", result);
	return (0);
}
*/
