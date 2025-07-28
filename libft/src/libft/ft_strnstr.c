/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 20:32:12 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 21:16:31 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strnstr - Locates the first occurrence of the substring 'needle' in the
	     string 'haystack' within the first 'len' characters.

@param haystack: A pointer to the string in which the search will be performed.
@param needle: A pointer to the substring to be searched for.
@param len: The maximum number of characters to search within 'haystack'.

@return: A pointer to the first occurrence of the substring 'needle'.
         NULL if 'needle' is not found within the specified length.
         If 'needle' is an empty string, returns the beginning of 'haystack'.
*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && needle[j] && (i + j) < len
			&& haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	*haystack = "Hello, world! Welcome to the world of C.";
	const char	*needle = "world";
	size_t		len = 20;
	char		*result;

	printf("ft_strnstr...\n");
	printf("@param haystack: %s\n", haystack);
	printf("@param needle: %s\n", needle);
	printf("@param len: %zu\n", len);

	result = ft_strnstr(haystack, needle, len);
        printf("\n@return: %s\n", result);

	return (0);
}
*/
