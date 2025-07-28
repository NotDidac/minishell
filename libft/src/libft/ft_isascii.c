/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:44:31 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:20:43 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isascii - Checks if a character is a valid ASCII character.

@param c: The character to be checked, passed as an int.

@return: 1 if the character is within the ASCII range (0-127).
         0 otherwise.
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
