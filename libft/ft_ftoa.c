/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 06:29:03 by patrisor          #+#    #+#             */
/*   Updated: 2019/12/23 06:51:07 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		itoa_stack(int x, char str[], int d)
{
	int		i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	ft_strrev(str, i);
	str[i] = '\0';
	return(i);
}

void	ft_ftoa(float n, char* res, int afterpoint)
{
	int		ipart;
	float	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	i = itoa_stack(ipart, res, 0);
	if (afterpoint != 0)
	{
		res[i] = '.';
		fpart = fpart * ft_pow(10, afterpoint) + 0.5;;
		itoa_stack((int)fpart, res + i + 1, afterpoint);
	}
}
