/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:44:51 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 19:27:08 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_memset - Fills the first 'n' bytes of the memory area pointed to by 's'
            with the specified fill value 'c'.

@param s: A pointer to the memory area to be filled.
@param c: The value to be set, passed as an integer.
@param n: The number of bytes to be set to the value 'c'.

@return: A pointer to the memory area 's'.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = (unsigned char)c;
		i++;
	}
	return ((char *)s);
}

/*
int	main(void)
{
	char	str[20] = "Hello, world !";
	char	c = 'x';
	int	n = 5;
	void	*result;

	printf("ft_memset...\n");
	printf("@param s: %s\n", str);
	printf("@param c: %c\n", c);
	printf("@param n: %i\n", n);

	result = ft_memset(str, c, n);
	printf("\n@return: %s\n", (char *)result);

	return (0);
}
*/
