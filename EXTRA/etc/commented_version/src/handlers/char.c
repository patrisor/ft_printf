/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 03:28:28 by pbondoer          #+#    #+#             */
/*   Updated: 2019/10/08 02:43:41 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function prints a single character onto output
int			pf_handle_char(t_pf_param param, va_list list)
{
	int		count;
	int		c;
	char	p;

	p = (param.flags & PF_FLAG_ZERO ? '0' : ' ');
	count = 0;
	c = va_arg(list, int);
	if ((param.flags & PF_FLAG_MINUS) == 0 && param.width > 1)
		count += pf_repeat(p, param.width - 1);
	count += pf_write((char *)&c, 1);
	if ((param.flags & PF_FLAG_MINUS) != 0 && param.width > 1)
		count += pf_repeat(' ', param.width - 1);
	return (count);
}
