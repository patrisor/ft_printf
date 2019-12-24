/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 00:26:36 by pbondoer          #+#    #+#             */
/*   Updated: 2019/10/07 22:38:17 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

extern inline void		*pf_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	while (size > 0)
	{
		size--;
		((unsigned char *)ptr)[size] = (unsigned char)0;
	}
	return (ptr);
}

extern inline char		*pf_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

extern inline size_t	pf_strlen(const char *s, const size_t max)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && i < max)
		i++;
	return (i);
}

// Check if current byte is digit
extern inline int		pf_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
