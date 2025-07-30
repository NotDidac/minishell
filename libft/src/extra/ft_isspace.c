/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:25:51 by didguill          #+#    #+#             */
/*   Updated: 2025/07/30 16:27:43 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isspace - Checks if a character is a whitespace character.

@param c: The character to be checked, passed as an int.

@return: 1 if the character is a whitespace character (space, tab, newline,
         vertical tab, form feed, or carriage return), 0 otherwise.
*/

#include "libft.h"

int	ft_isspace(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (character == ' ' || character == '\t' || character == '\n'
		|| character == '\v' || character == '\f' || character == '\r')
		return (1);
	return (0);
}
