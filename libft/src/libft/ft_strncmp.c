/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:08:38 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 20:02:07 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strncmp - Compares the first 'n' characters of the strings 's1' and 's2'.

@param s1: A pointer to the first string to be compared.
@param s2: A pointer to the second string to be compared.
@param n: The number of characters to compare.

@return: A negative value if 's1' is less than 's2'.
         A positive value if 's1' is greater than 's2'.
         0 if the first 'n' characters of both strings are equal.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

/*
int	main(void)
{
	const char	*s1 = "Hello, world!";
	const char	*s2 = "Hello, there!";
	size_t		n = 6;
	int		result;

	printf("ft_strncmp...\n");
	printf("@param s1: %s\n", s1);
	printf("@param s2: %s\n", s2);
	printf("@param n: %zu\n", n);

	result = ft_strncmp(s1, s2, n);
	printf("\n@return: %d\n", result);

	return (0);
}
*/
