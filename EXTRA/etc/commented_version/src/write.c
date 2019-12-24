/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 01:31:24 by pbondoer          #+#    #+#             */
/*   Updated: 2019/10/08 00:41:06 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** TODO: Change this to use a buffer system
*/
// Wrapper for write sys call
int			pf_write(const char *str, const size_t len)
{
	write(1, str, len);
	return (len);
}

// ft_putstr
int			pf_repeat(const char c, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		pf_write(&c, 1);
		i++;
	}
	return (i);
}
