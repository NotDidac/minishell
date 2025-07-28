/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:45:07 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:24:30 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_tolower - Converts an uppercase letter to its lowercase equivalent.

@param c: The character to be converted, passed as an int.

@return: The lowercase version of the character if it's an uppercase letter.
         The character itself unchanged if it's not a uppercase letter.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
