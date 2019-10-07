/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 03:26:05 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/04 00:05:12 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * A variadic function is one which takes a variable number of arguments
 */
int		main(int argc, char **argv)
{
	if (argc < 2)
		return -1;
	ft_printf(argv[1], argv[2]);
	return (0);
}
