/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:49:36 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:10:13 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strmapi - Applies a function to each character of a string.

@param s: The input string.
@param f: A pointer to the function to apply to each character.

@return: A new string resulting from applying the function to each character. 
         NULL if memory allocation fails or if 's' is NULL.
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result_str;

	if (!s)
		return (NULL);
	result_str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result_str[i] = f(i, s[i]);
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}

/*
char	to_upper_if_even(unsigned int index, char c)
{
	if (index % 2 == 0)
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*str = "abcdefghijklmnopkrstuvwxyz";
	char	*result = ft_strmapi(str, to_upper_if_even);

	printf("Original: %s\n", str);
	printf("Modified: %s\n", result);
	free(result);

	return 0;
}
*/
