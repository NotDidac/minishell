/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 17:43:22 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:09:50 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

bool	in(const char *str, char c)
{
	if (!str || !c)
		return (false);
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

int	ft_strnlen(const char *s, int maxlen)
{
	int	len;

	len = 0;
	while (len < maxlen && s[len] != '\0')
		len++;
	return (len);
}

void	ulong_to_ascii_base(t_ftp_fo *f, unsigned long num)
{
	if (num >= (unsigned long)f->base)
		ulong_to_ascii_base(f, num / f->base);
	if (f->specifier == 'X')
		f->buffer[f->num_len++] = FT_PRINTF_UP_HEX[num % f->base];
	else
		f->buffer[f->num_len++] = FT_PRINTF_LOW_HEX[num % f->base];
	f->buffer[f->num_len] = '\0';
}
