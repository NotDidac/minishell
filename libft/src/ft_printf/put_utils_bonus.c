/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 18:04:03 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:11:05 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_chars(char c, int num, t_f_da *d)
{
	if (num <= 0)
		return ;
	while (num--)
		d->chars_written += write(1, &c, 1);
}

void	put_substr(char *str, int num, t_f_da *d)
{
	int	i;

	if (!str)
		d->chars_written += write(1, "(null)", 6);
	if (num <= 0)
		return ;
	i = 0;
	while (num-- && str[i])
		d->chars_written += write(1, &str[i++], 1);
}

static void	put_0x(t_ftp_fo *f, t_f_da *d)
{
	if ((in("xX", f->specifier) && f->hash && f->buffer[0] != '0')
		|| f->specifier == 'p')
	{
		if (f->specifier == 'X')
			put_substr("0X", 2, d);
		else
			put_substr("0x", 2, d);
	}
}

void	put_sign(int sign, t_ftp_fo *f, t_f_da *d)
{
	if (f->base == 16)
		put_0x(f, d);
	else if (sign)
		put_chars('-', 1, d);
	else if (f->plus)
		put_chars('+', 1, d);
	else if (f->space)
		put_chars(' ', 1, d);
}
