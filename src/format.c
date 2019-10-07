/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:44:22 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/04 04:33:18 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO:DELETE
#include <stdio.h>

#include <ft_printf.h>

/*
 *
 */
int					get_argument(const char *str, size_t len, int is_valid,
							va_list list)
{
	return ((*str == '%' && is_valid) ? (pf_transform(pf_get_param(str, len), list)) 
			: (pf_write(str, len)));
}

/*
 * Scans valid bytes in the flag string
 */
static int			parse_inner(const char *str, size_t *i, int *valid)
{
	// If we are on the first index
	if (!str[*i])
		return (1);
	// while the memory area exists, there are valid flags found in the parsing, 
	// and the byte read is not a conversion flag, then  keep iterating.
	while (str[*i] && pf_is_valid(str[*i]) && !pf_is_conversion(str[*i]))
		(*i)++;
	// Dereferences and sets some data to valid variable (which will be a pointer 
	// to valid data), and checks if that data is valid; if so, then it will iterate
	if ((*valid = str[*i] && pf_is_valid(str[*i])))
		(*i)++;
	else
		// Invalid byte
		return (1);
	// Finished parsing
	return (0);
}

/* 
 * Traverse through first parameter of printf. If a percent variable was found, then 
 * scan next byte(s). If byte is invalid, then keep iterating
 * Parse a format string and print stuff
 */
int		pf_parse_format(const char *str, va_list list)
{
	size_t			i;
	size_t			start;
	int				valid;
	int				count;

	i = 0;
	count = 0;
	// Traverse through first parameter of printf
	while (str[i])
	{
		start = i;
		valid = 0;
		// If a percent variable was found, then iterate and ...
		if (str[i] == '%')
		{
			i++;
			// Scans whole string to see if valid data is passed
			if (parse_inner(str, &i, &valid))
				// Continues if we are on the first index or data is invalid
				continue;
		}
		else
			// If the memory area exists, but no % was found, then keep iterating
			while (str[i] && str[i] != '%')
				i++;
		//
		count += get_argument(str + start, i - start, valid, list);
	}
	return (count);
}
