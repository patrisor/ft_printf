/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 03:34:23 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/04 03:37:36 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Fills a memory spot with zeroes and returns the first address to that spot
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

// Returns character if found within string
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

// Returns length of string
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

// Checks if character is digit or not, returns 1 if true, else 0
extern inline int		pf_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
