/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:59:06 by didguill          #+#    #+#             */
/*   Updated: 2024/12/23 22:12:33 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_atoi - Converts the initial portion of the string 'nptr' to an int.

@param nptr: A pointer to the string to be converted.

@return: - The int representation of the string. 
	 - 0 if no valid conversion is found.
         If the string starts with a '+' or '-' sign, 
	 the result will be positive or negative accordingly.
         Whitespace characters at the beginning of the string are ignored.
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
int	main(void)
{
	const char	*str1 = "   -42";
	const char	*str2 = "12345";
	const char	*str3 = "   +678";
	const char	*str4 = "   123abc";
	const char	*str5 = "   abc123";

	printf("ft_atoi...\n");
	printf("@param str1: \"%s\" -> @return: %d\n", str1, ft_atoi(str1));
	printf("@param str2: \"%s\" -> @return: %d\n", str2, ft_atoi(str2));
	printf("@param str3: \"%s\" -> @return: %d\n", str3, ft_atoi(str3));
	printf("@param str4: \"%s\" -> @return: %d\n", str4, ft_atoi(str4));
	printf("@param str5: \"%s\" -> @return: %d\n", str5, ft_atoi(str5));

	return (0);
}
*/
