/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:44:55 by didguill          #+#    #+#             */
/*   Updated: 2024/12/29 17:30:11 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strlen - Calculates the length of a null-terminated string.

@param s: A pointer to the null-terminated string.

@return: The length of the string, not including the null terminator.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0')
		length++;
	return (length);
}

/*
int	main(void)
{
	char	str[] = "Hello, world!";
	size_t	result;

	printf("ft_strlen...\n");
	printf("@param s: %s\n", str);

	result = ft_strlen(str);
	printf("\n@return: %zu\n", result);

	return (0);
}
*/
