/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:18:39 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 22:35:20 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_substr - Allocates and returns a substring from the string 's',
	    starting from 'start' and with a maximum length of 'len'.

@param s: A pointer to the original string.
@param start: The starting index of the substring.
@param len: The maximum length of the substring.

@return: - A pointer to the newly allocated substring.
	 - NULL if memory allocation fails.
         - If the 'start' index is beyond the length of 's',
	   an empty string is returned.
         The result is null-terminated.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	substring_size;
	char	*result_substr;

	if (!s)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	substring_size = ft_strlen(s + start);
	if (substring_size < len)
		len = substring_size;
	result_substr = (char *)malloc((len + 1) * sizeof(char));
	if (!result_substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result_substr[i] = s[start + i];
		i++;
	}
	result_substr[i] = '\0';
	return (result_substr);
}

/*
int	main(void)
{
	const char	*str = "Hello, world!";
	unsigned int	start = 7;
	size_t		len = 5;
	char		*substr;

	printf("ft_substr...\n");
	printf("@param str: \"%s\"\n", str);
	printf("@param start: %u\n", start);
	printf("@param len: %zu\n", len);

	substr = ft_substr(str, start, len);
        printf("\n@return: \"%s\"\n", substr);
        free(substr);

	return (0);
}
*/
