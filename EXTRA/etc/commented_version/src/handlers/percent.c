/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 18:53:18 by pbondoer          #+#    #+#             */
/*   Updated: 2019/10/08 02:45:19 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function prints a single '%' byte, accounting for padding
int			pf_handle_percent(t_pf_param param, va_list list)
{
	int		count;
	char	p;

	(void)list;
	p = (param.flags & PF_FLAG_ZERO ? '0' : ' ');
	count = 0;
	if ((param.flags & PF_FLAG_MINUS) == 0 && param.width > 1)
		count += pf_repeat(p, param.width - 1);
	count += pf_write("%", 1);
	if ((param.flags & PF_FLAG_MINUS) != 0 && param.width > 1)
		count += pf_repeat(' ', param.width - 1);
	return (count);
}
