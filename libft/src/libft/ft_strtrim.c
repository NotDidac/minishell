/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:00:45 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 22:50:41 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strtrim - Allocates and returns a new string with the characters from the
	     start and end of 's1' removed if they are in the set 'set'.

@param s1: A pointer to the string to be trimmed.
@param set: A pointer to the set of characters to remove from both ends of 's1'.

@return: - A pointer to the newly allocated trimmed string.
	 - NULL if memory allocation fails.
         The result is null-terminated.
*/

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result_str;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	result_str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result_str)
		return (NULL);
	result_str[end - start] = '\0';
	i = 0;
	while (i < end - start)
	{
		result_str[i] = s1[start + i];
		i++;
	}
	return (result_str);
}

/*
int	main(void)
{
	const char	*s1 = "    whatHello, world!   t h aaattta";
	const char	*set = " what";
	char		*trimmed_str;

	printf("ft_strtrim...\n");
	printf("@param s1: \"%s\"\n", s1);
	printf("@param set: \"%s\"\n", set);

	trimmed_str = ft_strtrim(s1, set);
        printf("\n@return: \"%s\"\n", trimmed_str);
        free(trimmed_str);

	return (0);
}
*/
