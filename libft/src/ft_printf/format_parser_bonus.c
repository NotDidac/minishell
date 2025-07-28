/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:19:58 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:15:23 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
get_value - Gets an integer value from the format specifier.
	    (width) or (.precision)

If the format specifier has '*', gets the value from va_arg.
*/
static int	get_value(t_f_da *d, int *value)
{
	if (d->str[d->index] == '*')
	{
		*value = va_arg(d->ap, int);
		d->index++;
		return (FT_PRINTF_OK);
	}
	*value = 0;
	while (in("0123456789", d->str[d->index]))
	{
		*value = *value * 10 + d->str[d->index] - '0';
		d->index++;
	}
	return (FT_PRINTF_OK);
}

static void	parse_flags(t_f_da *d, t_ftp_fo *f)
{
	char	flag;

	while (in("-0# +", d->str[d->index]))
	{
		flag = d->str[d->index];
		if (flag == '-')
			f->left = true;
		else if (flag == '0')
			f->zero_pad = true;
		else if (flag == '#')
			f->hash = true;
		else if (flag == ' ')
			f->space = true;
		else if (flag == '+')
			f->plus = true;
		d->index++;
	}
}

/*
parse_format - Parses a format specifier.

This function processes the format string starting from the current index,
extracting (flags), (width), (.precision), and (specifier). 

It updates the format structure with the parsed values.

@return: - FT_PRINTF_OK
	 - FT_PRINTF_PARSE_ERROR
*/
int	parse_format(t_f_da *d, t_ftp_fo *f)
{
	parse_flags(d, f);
	get_value(d, &f->width);
	if (d->str[d->index] == '.' && d->str[d->index + 1])
	{
		d->index++;
		get_value(d, &f->precision);
	}
	if (!in("cspdiuxX%", d->str[d->index]))
		return (FT_PRINTF_PARSE_ERROR);
	f->specifier = d->str[d->index];
	if (in("diu", f->specifier))
		f->base = 10;
	else if (in("xXp", f->specifier))
		f->base = 16;
	d->index++;
	return (FT_PRINTF_OK);
}
