/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 03:16:10 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/04 03:37:58 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>

# define PF_FLAG_NONE 0
# define PF_FLAG_HASH 1
# define PF_FLAG_ZERO 2
# define PF_FLAG_MINUS 4
# define PF_FLAG_PLUS 8
# define PF_FLAG_SPACE 16
# define PF_FLAG_APOSTROPHE 32

typedef struct	s_pf_string
{
	const char		*str;
	size_t			length;
}				t_pf_string;

typedef enum	e_pf_modifier
{
	NONE = 0, L = 1, H = 2, J = 3, Z = 4, LL = 5, HH = 6
}				t_pf_modifier;

typedef struct	s_pf_argument
{
	size_t			position;
	size_t			length;
	t_pf_string		str;
}				t_pf_argument;

typedef struct	s_pf_param
{
	t_pf_string		str;
	t_pf_modifier	modifier;
	int				access;
	int				flags;
	int				width_access;
	int				precision;
	int				error;
	unsigned int	width;
	char			conversion;
	void			*value;
}				t_pf_param;

/*
** Used when parsing formats and when doing the final substitution.
*/

typedef struct	s_pf_handle
{
	char			conversion;
	int				(*handle)(t_pf_param, va_list);
}				t_pf_handle;

/*
** Handlers
*/

int				pf_handle_percent(t_pf_param param, va_list list);
int				pf_handle_char(t_pf_param param, va_list list);
int				pf_handle_string(t_pf_param param, va_list list);
int				pf_handle_hex(t_pf_param param, va_list list);

int				pf_write_chunk(const char *str, int free, size_t len,
					t_pf_param param);

/*
** Core
*/

int				ft_printf(const char *format, ...);

int				pf_parse_format(const char *str, va_list list);
int				pf_transform(t_pf_param param, va_list list);

int				pf_write(const char *str, const size_t len);
int				pf_repeat(const char c, size_t len);

int				pf_is_conversion(const char c);
int				pf_is_modifier(const char c);
int				pf_is_flag(const char c);
int				pf_is_valid(const char c);
t_pf_param		pf_param(const char *str, const size_t len);
t_pf_string		pf_string(const char *str, size_t len);
t_pf_param		pf_get_param(const char *str, size_t len);

/*
** Helper functions
*/

int				pf_atoi(const char *str, int allow_neg, int *result, size_t *i);
char			*pf_itoa(intmax_t n, t_pf_param param, char sign);
char			*pf_uitoa(uintmax_t n, unsigned int base, const char *digits,
					size_t precision);
void			*pf_memalloc(size_t size);
char			*pf_strchr(const char *s, int c);
size_t			pf_strlen(const char *s, const size_t max);
int				pf_isdigit(int c);
char			*pf_strjoin(char *a, char *b);
int				pf_max(int a, int b);
int				pf_get_base(char c);

/*
** Handlers
 */

int			handle_access(t_pf_param *param, const char *str, size_t *i);
int			handle_flags(t_pf_param *param, const char *str, size_t *i);
int			handle_width(t_pf_param *param, const char *str, size_t *i);
int			handle_precision(t_pf_param *p, const char *str, size_t *i);
int			handle_modifier(t_pf_param *p, const char *str, size_t *i);
int			handle_conversion(t_pf_param *p, const char *str, size_t *i);
t_pf_param	get_param(const char *str, size_t len);

#endif
