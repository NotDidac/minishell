/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:21:06 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 12:27:05 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strlcat - Appends up to 'size - dest_len - 1' characters from the string 'src'
             to the string 'dest', ensuring the result is null-terminated.

@param dest: A pointer to the destination string, which will be appended to.
@param src: A pointer to the source string, which will be appended to 'dest'.
@param size: The total size of the destination buffer, 
	     including space for the null terminator.

@return: The total length of the string 'dest' and 'src' after concatenation.
         If the size <= length of 'dest', returns 'size + src_len'.
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] && dest_len < size)
		dest_len++;
	while (src[src_len])
		src_len++;
	if (dest_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dest_len + i + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*
int	main(void)
{
	char	dest[20] = "Hello, ";
	char	src[] = "world!";
	size_t	size = 15;
	size_t	result;

	printf("ft_strlcat...\n");
	printf("@param dest: %s\n", dest);
	printf("@param src: %s\n", src);
	printf("@param size: %zu\n", size);

	result = ft_strlcat(dest, src, size);
	printf("\n@return: %zu\n", result);
	printf("dest: %s\n", dest);

	return (0);
}
*/
