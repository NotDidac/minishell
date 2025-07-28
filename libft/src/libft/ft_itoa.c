/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:50:46 by didguill          #+#    #+#             */
/*   Updated: 2024/12/24 12:45:58 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_itoa - Converts an int to a string.

@param n: The int to convert.

@return: A pointer to a string representing the number.
	 NULL if memory allocation fails.
*/

#include "libft.h"

static size_t	get_digit_count(int number)
{
	size_t	digit_count;

	digit_count = 0;
	if (number <= 0)
	{
		if (number == 0)
			return (1);
		if (number == -2147483648)
			return (11);
		number = -number;
		digit_count++;
	}
	while (number > 0)
	{
		digit_count++;
		number /= 10;
	}
	return (digit_count);
}

static char	*fill_result_str(char *result_str, size_t digit_count, int number)
{
	if (number == 0)
	{
		result_str[0] = '0';
		return (result_str);
	}
	if (number < 0)
	{
		result_str[0] = '-';
		if (number == -2147483648)
		{
			result_str[--digit_count] = '8';
			number = -(number / 10);
		}
		else
			number = -number;
	}
	while (number > 0)
	{
		result_str[--digit_count] = (number % 10) + '0';
		number /= 10;
	}
	return (result_str);
}

char	*ft_itoa(int n)
{
	size_t	digit_count;
	char	*result_str;

	digit_count = get_digit_count(n);
	result_str = (char *)malloc((digit_count + 1) * sizeof(char));
	if (!result_str)
		return (NULL);
	result_str[digit_count] = '\0';
	result_str = fill_result_str(result_str, digit_count, n);
	return (result_str);
}
