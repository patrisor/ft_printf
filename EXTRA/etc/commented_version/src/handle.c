/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 08:21:00 by pbondoer          #+#    #+#             */
/*   Updated: 2019/10/08 00:00:17 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"
#include "helpers.h"

// Check if byte is digit or '$' byte accordingly, then store it into access
int			handle_access(t_pf_param *param, const char *str, size_t *i)
{
	int access;
	int t;

	t = *i;
	// Check if current byte is not a digit
	if (!pf_isdigit(str[*i]))
		return (0);
	// Convert string into into (stored in access)
	if (pf_atoi(str, 0, &access, i) || str[*i] != '$')
	{
		*i = t;
		return (0);
	}
	(*i)++;
	param->access = access;
	return (0);
}

/*
 * PF_FLAG_NONE = 0
 * PF_FLAG_HASH = 1
 * PF_FLAG_ZERO = 2
 * PF_FLAG_MINUS = 4
 * PF_FLAG_PLUS = 8
 * PF_FLAG_SPACE = 16
 * PF_FLAG_APOSTROPHE = 32
 */
int			handle_flags(t_pf_param *param, const char *str, size_t *i)
{
	char c;

	while (*i < param->str.length)
	{
		c = str[*i];
		// Checks if the byte is equal to any of these -> "#0-+' "
		if (pf_is_flag(c))
		{
			if (c == '#')
				param->flags |= PF_FLAG_HASH;
			else if (c == '0')
				param->flags |= PF_FLAG_ZERO;
			else if (c == '-')
				param->flags |= PF_FLAG_MINUS;
			else if (c == '+')
				param->flags |= PF_FLAG_PLUS;
			else if (c == ' ')
				param->flags |= PF_FLAG_SPACE;
			else if (c == '\'')
				param->flags |= PF_FLAG_APOSTROPHE;
		}
		else
			return (0);
		(*i)++;
	}
	return (1);
}

// Converts next byte in line into an int and stores into either width_access or witdth 
// paraeters based on if '*' byte was encountered.
int			handle_width(t_pf_param *param, const char *str, size_t *i)
{
	int width;
	int is_pos;

	if ((is_pos = (str[*i] == '*')))
		(*i)++;
	if (pf_atoi(str, 0, &width, i) && !is_pos)
		return (1);
	if (is_pos)
	{
		if (str[*i] == '$')
			(*i)++;
		else
			return (1);
		param->width_access = width;
	}
	else
		param->width = width;
	return (0);
}

// Scans for the period byte until found, then modifies the precision parameter accordingly
// based on the size of the next number
int			handle_precision(t_pf_param *p, const char *str, size_t *i)
{
	int precision;

	p->precision = -1;
	if (str[*i] != '.')
		return (0);
	p->precision = 0;
	(*i)++;
	if (pf_atoi(str, 0, &precision, i))
		return (1);
	p->precision = precision;
	return (0);
}

// Scans the byte to see if it a certain modifier. If so, it stores that into
// modifier parameter of printf object
int			handle_modifier(t_pf_param *p, const char *str, size_t *i)
{
	t_pf_modifier	m;

	m = NONE;
	if (!pf_is_modifier(str[*i]))
		return (0);
	// Long vs Long Long
	if (str[*i] == 'l')
	{
		if (str[*i + 1] == 'l' && ++(*i))
			m = LL;
		else
			m = L;
	}
	// Short vs unsigned short
	else if (str[*i] == 'h')
	{
		if (str[*i + 1] == 'h' && ++(*i))
			m = HH;
		else
			m = H;
	}
	// conversion specifier applies to an argument with type pointer to intmax_t 
	// or uintmax_t
	else if (str[*i] == 'j')
		m = J;
	// size_t modifier
	else if (str[*i] == 'z')
		m = Z;
	p->modifier = m;
	return ((*i)++ & 0);
}
