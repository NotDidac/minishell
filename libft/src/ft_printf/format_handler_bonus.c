/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:22:34 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:15:58 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
print_format - Handles printing based on the format specifier.

@return: - FT_PRINTF_OK
	 - FT_PRINTF_MALLOC_ERROR
*/
int	print_format(t_f_da *d, t_ftp_fo *f)
{
	if (init_format_buffer(f) != FT_PRINTF_OK)
		return (FT_PRINTF_MALLOC_ERROR);
	if (f->specifier == 'c')
		print_char_f(d, f, va_arg(d->ap, int));
	else if (f->specifier == 's')
		print_str_f(d, f, va_arg(d->ap, char *));
	else if (in("di", f->specifier))
		print_num_f(d, f, (long)va_arg(d->ap, int), FT_P_S);
	else if (f->specifier == 'p')
		print_num_f(d, f, (unsigned long)va_arg(d->ap, void *), FT_P_U);
	else if (in("uxX", f->specifier))
		print_num_f(d, f, (unsigned long)va_arg(d->ap, unsigned int), FT_P_U);
	else
		put_chars('%', 1, d);
	free(f->buffer);
	return (FT_PRINTF_OK);
}
