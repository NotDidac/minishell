/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:34:14 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 20:19:57 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_memcmp - Compares the first 'n' bytes of the memory areas 's1' and 's2'.

@param s1: A pointer to the first memory area to be compared.
@param s2: A pointer to the second memory area to be compared.
@param n: The number of bytes to compare.

@return: A negative int if s1[byte] is smaller than in s2[byte].
	 A positive int if s1[byte] is bigger than in s2[byte].
         0 if the first 'n' bytes of both memory areas are equal.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	const char	s1[] = "Hello, world!";
	const char	s2[] = "Hello, World!";
	size_t		n = 13;
	int		result;

	printf("ft_memcmp...\n");
	printf("@param s1: %s\n", s1);
	printf("@param s2: %s\n", s2);
	printf("@param n: %zu\n", n);

	result = ft_memcmp(s1, s2, n);
	printf("\n@return: %d\n", result);

	return (0);
}
*/
