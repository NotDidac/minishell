/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:44:15 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 14:19:50 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_isdigit - Checks if a character is a digit (0-9).

@param c: The character to be checked, passed as an int.

@return: 1 if the character is a digit.
         0 otherwise.
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
