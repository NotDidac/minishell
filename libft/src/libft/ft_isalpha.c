/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:44:06 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:19:10 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isalpha - Checks if a character is an alphabetic letter.

@param c: The character to be checked, passed as an int.

@return: 1 if the character is an alphabetic letter.
         0 otherwise.
*/

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
