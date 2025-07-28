/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:43:12 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:23:34 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_toupper - Converts a lowercase letter to its uppercase equivalent.

@param c: The character to be converted, passed as an int.

@return: The uppercase version of the character if it's a lowercase letter.
         The character itself unchanged if it's not a lowercase letter.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
