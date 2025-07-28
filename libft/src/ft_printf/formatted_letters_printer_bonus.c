/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatted_letters_printer_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:34:45 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:11:05 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "libft.h"

static char	*set_str_to_null(t_ftp_fo *f)
{
	if (f->precision > 0 && f->precision < 6)
		return ("");
	else
		return ("(null)");
}

void	print_str_f(t_f_da *d, t_ftp_fo *f, char *str)
{
	int	num_spaces;
	int	len;

	if (!str)
		str = set_str_to_null(f);
	if (f->precision >= 0)
		len = ft_strnlen(str, f->precision);
	else
		len = ft_strlen(str);
	num_spaces = f->width - len;
	if (num_spaces < 0)
		num_spaces = 0;
	if (!f->left)
		put_chars(' ', num_spaces, d);
	put_substr(str, len, d);
	if (f->left)
		put_chars(' ', num_spaces, d);
}

void	print_char_f(t_f_da *d, t_ftp_fo *f, int c)
{
	if (!f->left && f->width > 1)
		put_chars(' ', f->width - 1, d);
	put_chars((char)c, 1, d);
	if (f->left && f->width > 1)
		put_chars(' ', f->width - 1, d);
}
