/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 11:38:38 by didguill          #+#    #+#             */
/*   Updated: 2025/03/06 12:16:31 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

/* Macros */
# define FT_PRINTF_UP_HEX		"0123456789ABCDEF"
# define FT_PRINTF_LOW_HEX	"0123456789abcdef"
# define FT_PRINTF_BUFFER_SIZE	65
# define FT_P_U		true
# define FT_P_S		false

/* Error Enumeration */
typedef enum e_ft_printf_error
{
	FT_PRINTF_OK = 0,
	FT_PRINTF_PARSE_ERROR = -1,
	FT_PRINTF_MALLOC_ERROR = -2,
}	t_ft_printf_error;

/* Data Structure */
typedef struct s_f_da
{
	const char	*str;
	int			index;
	va_list		ap;
	int			chars_written;
}	t_f_da;

/* Format Structure */
typedef struct s_ftp_fo
{
	bool	left;
	bool	zero_pad;
	bool	hash;
	bool	space;
	bool	plus;
	char	specifier;
	char	*buffer;
	int		num_len;
	int		width;
	int		precision;
	int		base;
}	t_ftp_fo;

/* Main Functions */
int		ft_printf(char const *format, ...);
int		parse_format(t_f_da *d, t_ftp_fo *f);
int		print_format(t_f_da *d, t_ftp_fo *f);

/* Init Functions*/
int		init_format_buffer(t_ftp_fo *f);
void	init_t_f_da(t_f_da *d, const char *f);
void	init_fo(t_ftp_fo *f);

/* Put Functions */
void	put_chars(char c, int num, t_f_da *d);
void	put_substr(char *str, int num, t_f_da *d);
void	put_sign(int sign, t_ftp_fo *f, t_f_da *d);

/* Format Printer Functions */
void	print_char_f(t_f_da *d, t_ftp_fo *f, int c);
void	print_str_f(t_f_da *d, t_ftp_fo *f, char *str);
void	print_num_f(t_f_da *d, t_ftp_fo *f, long long num, bool is_unsigned);

/* Helper Functions */
bool	in(const char *str, char c);
void	ulong_to_ascii_base(t_ftp_fo *f, unsigned long num);
int		ft_strnlen(const char *s, int maxlen);
#endif
