/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_numbers_printer_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:25:31 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:11:05 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	get_sign_value(long *num, bool is_unsigned)
{
	if (is_unsigned)
		return (0);
	else if (*num < 0)
	{
		*num = -(*num);
		return (1);
	}
	return (0);
}

static int	get_num_zeros(t_ftp_fo *f, int sign)
{
	int	result;

	if (f->precision >= 0 && f->precision > f->num_len)
		return (f->precision - f->num_len);
	if (f->precision >= 0 && f->zero_pad)
		return (0);
	if (f->zero_pad && !f->left)
	{
		result = f->width - f->num_len;
		if ((in("xX", f->specifier) && f->hash && f->buffer[0] != '0')
			|| f->specifier == 'p')
			result -= 2;
		else if (f->specifier != 'u' && (sign > 0 || f->plus || f->space))
			result -= 1;
		if (result > 0)
			return (result);
	}
	return (0);
}

static int	get_num_spaces(t_ftp_fo *f, int sign, int num_zeros)
{
	int		result;

	result = f->width - num_zeros - f->num_len;
	if (in("uxXp", f->specifier))
	{
		if ((in("xX", f->specifier) && f->hash && f->buffer[0] != '0')
			|| f->specifier == 'p')
			result -= 2;
	}
	else if (sign > 0 || f->plus || f->space)
		result -= 1;
	if (result > 0)
		return (result);
	return (0);
}

static bool	is_special_case(t_f_da *d, t_ftp_fo *f, long long num)
{
	if (f->precision == 0 && num == 0)
	{
		put_chars(' ', f->width, d);
		return (true);
	}
	else if (f->specifier == 'p' && !num)
	{
		if (f->width > 5 && !f->left)
			put_chars(' ', f->width - 5, d);
		d->chars_written += write(1, "(nil)", 5);
		if (f->width > 5 && f->left)
			put_chars(' ', f->width - 5, d);
		return (true);
	}
	return (false);
}

void	print_num_f(t_f_da *d, t_ftp_fo *f, long long num, bool is_unsigned)
{
	int		sign;
	int		num_zeros;
	int		num_spaces;

	if (is_special_case(d, f, num))
		return ;
	sign = get_sign_value((long *)&num, is_unsigned);
	ulong_to_ascii_base(f, num);
	num_zeros = get_num_zeros(f, sign);
	num_spaces = get_num_spaces(f, sign, num_zeros);
	if (f->left)
	{
		put_sign(sign, f, d);
		put_chars('0', num_zeros, d);
		put_substr(f->buffer, f->num_len, d);
		put_chars(' ', num_spaces, d);
	}
	else
	{
		put_chars(' ', num_spaces, d);
		put_sign(sign, f, d);
		put_chars('0', num_zeros, d);
		put_substr(f->buffer, f->num_len, d);
	}
}
