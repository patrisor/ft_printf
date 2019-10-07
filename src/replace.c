/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 04:22:35 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/04 04:28:21 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Replaces conversion with string (one param)
*/
int			pf_transform(t_pf_param param, va_list list)
{
	static t_pf_handle	(handle[12]) = {
		{ .conversion = 's', .handle = pf_handle_string },
		{ .conversion = 'S', .handle = pf_handle_string },
		{ .conversion = 'c', .handle = pf_handle_char },
		{ .conversion = 'C', .handle = pf_handle_char },
		{ .conversion = '%', .handle = pf_handle_percent },
		{ .conversion = 'd', .handle = pf_handle_hex },
		{ .conversion = 'x', .handle = pf_handle_hex },
		{ .conversion = 'X', .handle = pf_handle_hex },
		{ .conversion = 'p', .handle = pf_handle_hex },
		{ .conversion = 'u', .handle = pf_handle_hex },
		{ .conversion = 'U', .handle = pf_handle_hex },
		{ .conversion = 'o', .handle = pf_handle_hex }
	};
	int					i;

	// If error in code, return zero
	if (param.error)
		return (0);
	// Iterate through full list of conversions and see if any of them match...
	i = -1;
	while (++i < 12)
		if (param.conversion == handle[i].conversion)
			// handle() is conveniently named that as a reference to another
			// function passed in that particular list of conversions (dispatch
			// table)
			return (handle[i].handle(param, list));
	return (0);
}
