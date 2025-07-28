/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:44:22 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:20:21 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isalnum - Checks if a character is alphanumeric.

@param c: The character to be checked, passed as an int.

@return: 1 if the character is alphanumeric.
         0 otherwise.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	character;

	character = (unsigned char)c;
	if (ft_isalpha(character) || ft_isdigit(character))
		return (1);
	else
		return (0);
}
