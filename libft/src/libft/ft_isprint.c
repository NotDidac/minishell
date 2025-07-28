/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:44:39 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:21:05 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isprint - Checks if a character is a printable character.

@param c: The character to be checked, passed as an int.

@return: 1 if the character is a printable character.
         0 otherwise.
*/

int	ft_isprint(int c)
{
	unsigned int	character;

	character = (unsigned int)c;
	if (character >= ' ' && character <= '~')
		return (1);
	else
		return (0);
}
