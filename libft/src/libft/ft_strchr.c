/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:45:33 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 19:48:00 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strchr - Locates the first occurrence of the character 'c' in the string 's'.

@param s: A pointer to the string to be searched.
@param c: The character to search for, passed as an int.

@return: A pointer to the first found character 'c' in the string 's'.
         NULL if the character is not found.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

/*
int	main(void)
{
	const char	*str = "Hello, world!";
	int		c = 'o';
	char	*result;

	printf("ft_strchr...\n");
	printf("@param s: %s\n", str);
	printf("@param c: %c\n", c);

	result = ft_strchr(str, c);
	printf("\n@return: %s\n", result);

	return (0);
}
*/
