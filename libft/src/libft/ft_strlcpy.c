/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:20:56 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 20:34:29 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strlcpy - Copies up to 'size - 1' characters from the string 'src' to 'dest'
             and ensures the destination string is null-terminated.

@param dest: A pointer to the destination string.
@param src: A pointer to the source string to be copied.
@param size: The maximum number of characters to copy (including the null char).

@return: The total length of the source string 'src'.
         If 'size' > length of 'src', returns the length of 'src'.
         If 'size' is 0, returns the length of 'src' without modifying 'dest'.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	length;
	size_t	i;

	length = 0;
	i = 0;
	while (src[length])
		length++;
	if (size == 0)
		return (length);
	while (src[i] && size > 1)
	{
		dest[i] = src[i];
		size--;
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (length);
}

/*
int	main(void)
{
	char	src[] = "Hello, world!";
	char	dest[20];
	size_t	size = 6;
	size_t	result;

	printf("ft_strlcpy...\n");
	printf("@param src: %s\n", src);
	printf("@param size: %zu\n", size);

	result = ft_strlcpy(dest, src, size);
	printf("\n@return: %zu\n", result);
	printf("dest: %s\n", dest);

	return (0);
}
*/
