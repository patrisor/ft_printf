/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/17 08:24:34 by pbondoer          #+#    #+#             */
/*   Updated: 2019/10/08 02:36:43 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "handlers.h"

// Checks to see if current byte contains a conversion flag, if it exists, it stores 
// thaat flag into conversion parameter of object 
int					handle_conversion(t_pf_param *p, const char *str, size_t *i)
{
	if (pf_is_conversion(str[*i]))
	{
		p->conversion = str[*i];
		(*i)++;
		return (0);
	}
	return (1);
}

// CONVERTS ANY BIG CHARCTERS TO THEIR SMALL COUNTERPARTS and assigns long to the modifier
static t_pf_param	big_conversions(t_pf_param param)
{
	// If any of these big vonversions are stored, then Long is assigned as it's conversion
	if (param.conversion == 'D' || param.conversion == 'S' ||
			param.conversion == 'C' || param.conversion == 'O' ||
			param.conversion == 'U')
		param.modifier = L;
	if (param.conversion == 'D')
		param.conversion = 'd';
	if (param.conversion == 'S')
		param.conversion = 's';
	if (param.conversion == 'C')
		param.conversion = 'c';
	if (param.conversion == 'O')
		param.conversion = 'o';
	if (param.conversion == 'U')
		param.conversion = 'u';
	return (param);
}

// Build the printf object, filling it with different values based on what is stored inside of str 
// input
t_pf_param			pf_get_param(const char *str, size_t len)
{
	// Pointer to functions (handle_access, handle_flags, handle_width, 
	// handle_precision, handle_modifier, handle_conversion)
	static int		(*handle[6])(t_pf_param *, const char *, size_t *) = {
						handle_access, handle_flags, handle_width,
						handle_precision, handle_modifier, handle_conversion};
	// printf object
	t_pf_param		param;
	size_t			i;
	size_t			pos;

	i = 0;
	pos = 0;
	// Create a printf param object
	param = pf_param(str, len);
	// Iterate through handler functions to determine hwat type of flag is in parameter, 
	// manipulating the printf object accordingly
	while (i < 6)
	{
		// If any fuction returns 1, there was an error
		if ((*handle[i])(&param, str + 1, &pos))
		{
			param.error = 1;
			break ;
		}
		i++;
	}
	// If the conversion byte is an 'i', then it's converted to 'd'
	if (param.conversion == 'i')
		param.conversion = 'd';
	// If the conversion flag is a pointer byte, then it is assigned a long long int to the modifier
	if (param.conversion == 'p')
		param.modifier = LL;
	// CONVERTS ANY BIG CHARCTERS TO THEIR SMALL COUNTERPARTS and assigns long to the modifier
	return (big_conversions(param));
}   
