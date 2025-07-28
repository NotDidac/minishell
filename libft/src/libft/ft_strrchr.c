/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 11:25:30 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 19:57:06 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strrchr - Locates the last occurrence of the character 'c' in the string 's'.

@param s: A pointer to the string to be searched.
@param c: The character to search for, passed as an integer.

@return: A pointer to the last occurrence of the character 'c' in the string 's'.
         NULL if the character is not found.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last_index;

	last_index = ft_strlen(s);
	while (last_index >= 0)
	{
		if (s[last_index] == (char)c)
			return ((char *)s + last_index);
		last_index--;
	}
	return (NULL);
}

/*
int main(void)
{
	const char	*str = "Hello, world!";
	int		c = 'o';
	char	*result;

	printf("ft_strrchr...\n");
	printf("@param s: %s\n", str);
	printf("@param c: %c\n", c);

	result = ft_strrchr(str, c);
	printf("\n@return: %s\n", result);

	return (0);
}
*/
