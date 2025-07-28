/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:03:36 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:15:58 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
@param format: The input string.
*/
void	init_t_f_da(t_f_da *d, const char *format)
{
	d->str = format;
	d->index = 0;
	d->chars_written = 0;
}

void	init_fo(t_ftp_fo *f)
{
	f->left = false;
	f->zero_pad = false;
	f->hash = false;
	f->space = false;
	f->plus = false;
	f->width = 1;
	f->precision = -1;
	f->base = 0;
	f->num_len = 0;
}

int	init_format_buffer(t_ftp_fo *f)
{
	f->buffer = (char *)malloc(FT_PRINTF_BUFFER_SIZE * sizeof(char));
	if (!f->buffer)
		return (FT_PRINTF_MALLOC_ERROR);
	return (FT_PRINTF_OK);
}
