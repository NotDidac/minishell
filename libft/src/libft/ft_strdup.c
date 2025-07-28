/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:01:24 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 21:22:28 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strdup - Allocates and returns a new string that is a duplicate of
	    the string 's'.

@param s: A pointer to the string to be duplicated.

@return: A pointer to the newly allocated string that contains a copy of 's'.
         NULL if memory allocation fails.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicated_str;
	int		length;
	int		i;

	length = ft_strlen(s);
	duplicated_str = (char *)malloc((length + 1) * sizeof(char));
	if (!duplicated_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		duplicated_str[i] = s[i];
		i++;
	}
	duplicated_str[i] = '\0';
	return (duplicated_str);
}

/*
int	main(void)
{
	const char	*original = "Hello, world!";
	char		*duplicated;

	printf("ft_strdup...\n");
	printf("@param s: %s\n", original);

	duplicated = ft_strdup(original);
        printf("\n@return: %s\n", duplicated);
        free(duplicated);

	return (0);
}
*/
