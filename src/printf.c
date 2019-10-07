/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 22:48:41 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/03 23:49:34 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Similar to LibC implementation
// Three dots means ellipsis, or any number of optional arguments can go here.
int		ft_printf(const char *format, ...)
{
	// To use these stdarg.h functions, we need a variable capable of storing a 
	// variable-length argument list--this variable will be of type va_list
	va_list	list;
	int		result;

	// initializes the list for subsequent use by va_arg() and va_end()
	va_start(list, format);
	//
	// contains va_arg.
	result = pf_parse_format(format, list);
	// cleans up the variable argument list
	va_end(list);
	return (result);
}
