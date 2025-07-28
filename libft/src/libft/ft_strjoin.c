/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 10:30:19 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 22:42:20 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strjoin - Allocates and returns a new string that is the result of
	     concatenating 's1' and 's2'.

@param s1: A pointer to the first string to be concatenated.
@param s2: A pointer to the second string to be concatenated.

@return: - A pointer to the newly allocated string containing the concatenation
	   of 's1' and 's2',
         - NULL if memory allocation fails.
	 The result is null-terminated.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result_str;
	int		total_length;
	int		i;
	int		j;

	total_length = ft_strlen(s1) + ft_strlen(s2);
	result_str = (char *)malloc((total_length + 1) * sizeof(char));
	if (!result_str)
		return (NULL);
	result_str[total_length] = '\0';
	i = 0;
	while (s1[i] != '\0')
	{
		result_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result_str[i + j] = s2[j];
		j++;
	}
	return (result_str);
}

/*
int	main(void)
{
	const char	*s1 = "Hello, ";
	const char	*s2 = "world!";
	char		*joined_str;

	printf("ft_strjoin...\n");
	printf("@param s1: \"%s\"\n", s1);
	printf("@param s2: \"%s\"\n", s2);

	joined_str = ft_strjoin(s1, s2);
	printf("\n@return: \"%s\"\n", joined_str);
	free(joined_str);

	return (0);
}
*/
