/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:37:18 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:15:58 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
print_input - Processes the input string.

Iterates through the input string, checking for format specifiers.
It prints characters directly or calls functions to handle format specifiers.

@return: - FT_PRINTF_OK
	 - Error code
*/
static int	print_input(t_f_da *d)
{
	t_ftp_fo	format;

	while (d->str[d->index])
	{
		if (d->str[d->index] == '%' && d->str[d->index + 1])
		{
			d->index++;
			init_fo(&format);
			if (parse_format(d, &format) != FT_PRINTF_OK)
				return (FT_PRINTF_PARSE_ERROR);
			if (print_format(d, &format) != FT_PRINTF_OK)
				return (FT_PRINTF_MALLOC_ERROR);
		}
		else
		{
			d->chars_written += write(1, &d->str[d->index], 1);
			d->index++;
		}
	}
	return (FT_PRINTF_OK);
}

/*
ft_printf - A simplified implementation of the printf function.

@param format: A string containing text and format specifiers.
@param ... : Variable arguments that correspond to format specifiers.

@return: - Number of characters written to the output.
	 - Error code.
*/
int	ft_printf(char const *format, ...)
{
	int			error_code;
	t_f_da		data;

	va_start(data.ap, format);
	init_t_f_da(&data, format);
	error_code = print_input(&data);
	if (error_code != FT_PRINTF_OK)
	{
		va_end(data.ap);
		return (error_code);
	}
	va_end(data.ap);
	return (data.chars_written);
}
