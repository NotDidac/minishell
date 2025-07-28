/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:37:14 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 13:09:57 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_striteri - Applies a function to each character of a string.

@param s: The string to iterate over.
@param f: A pointer to the function to apply to each character.

This function does not return anything. 
It modifies the characters in the string directly.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	modify_char(unsigned int index, char *c)
{
	*c = 'A'  + index;
}

int	main(void)
{
	char	str[] = "Hello, World !";

	printf("Original: %s\n", str);

	ft_striteri(str, modify_char);
	printf("Modified: %s\n", str);

	return 0;
}
*/
