/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 05:09:03 by patrisor          #+#    #+#             */
/*   Updated: 2019/12/23 06:49:48 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdarg.h>
#include <limits.h>
// Delete
#include <stdio.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* *********************************AUXILIARY******************************** */
/* ************************************************************************** */
/* ************************************************************************** */

char	pt_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while(++i < (int)ft_strlen(s) + 1)
		if (*(s + i) == (char)c)
			return((char)c);
	return(0);
}

char	is_valid_conversion(const char c)
{
	return((pt_strchr("cspdDioOuUxXf", c)) ? c : 0);
}

void	pf_write(const char *format, int *out)
{
	write(1, format, 1);
	(*out)++;
}

void	pf_putstr(char *str, int *out)
{
	while(*str)
	{
		pf_write(str, out);
		str++;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* *********************************HANDLERS********************************* */
/* ************************************************************************** */
/* ************************************************************************** */

void	char_handler(va_list list, int *out)
{
	char	inp;

	inp = va_arg(list, char);
	pf_write(&inp, out);
}

void	int_handler(va_list list, int *out)
{
	char	*num;
	char	*tmp;

	num = ft_itoa(va_arg(list, int));
	tmp = num;
	while (*tmp)
	{
		pf_write(tmp, out);
		tmp++;
	}
	free(num);
}

void	hex_handler(unsigned long long int n, int *out, int c)
{
	char	hexa[24];
    int		i;
	int		j;
	int		tmp;
	
	i = 0;
	ft_memset(hexa, '0', sizeof(hexa));
	(n == 0) ? pf_write(&(hexa[0]), out) : 0;
	while (n != 0)
	{
		tmp = ((n % 16 < 10) ? (n % 16 + 48) : (n % 16 + 55));
		hexa[i++] = (ft_isupper(c)) ? ft_toupper(tmp) : ft_tolower(tmp);
		n = n / 16;
	}
	j = i - 1;
	while (j >= 0)
		pf_write(&(hexa[j--]), out);
}

// TODO: Work on this
void	pointer_handler(va_list list, int *out)
{
	void	*ptr;

	if ((ptr = (void *)va_arg(list, void *)))
		return ;
	hex_handler((unsigned long long int)ptr, out, 'a');
}

/* ************************************************************************** */
/* *********************************FLOATS*********************************** */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* *********************************PRINTF*********************************** */
/* ************************************************************************** */
/* ************************************************************************** */

// TODO:
// Handles Errors, ints, hex, octal
int		handle_args(const char *f, va_list l, int *o)
{
	char	a;
	
	if ((a = is_valid_conversion(f[1])))
	{
		// TODO: Expects uintmax_t from va_arg, then convert that into hex	
		(a == 'p') ? pointer_handler(l, o): 0;
		(a == 'c' || a == 's') ? ((a == 'c') ? char_handler(l, o) : 
				pf_putstr(va_arg(l, char *), o)) : 0;
		(a == 'd' || a == 'i') ? int_handler(l, o) : 0;
		// TODO: o and u flags
		if (a == 'x' || a == 'X') 
			hex_handler(va_arg(l, unsigned long long int), o, (int)a);
		//(a == 'f') ? float_handler(l, o) : 0;
		return(0);
	}
	return(1); // Returns 1 if error in input
}

int		ft_printf_internal(const char *f, va_list a)
{
	int		out;
	int		code;

	out = 0;
	while (*f)
	{ // TODO: Compress this
		code = -1;
		(*f == '%') ? (code = handle_args(f, a, &out)) : pf_write(f, &out);
		(!code) ? f++ : 0;
		f++;
	}
	return(out);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			done;

	va_start(arg, format);
	done = ft_printf_internal(format, arg);
	va_end(arg);
	return(done);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* **********************************TESTING********************************* */
/* ************************************************************************** */
/* ************************************************************************** */

int		main(int argc, char **argv)
{
	// REGULAR PRINTF
	//printf("%d\n", printf("%f\n", 69.42));
	// TODO: Figure out when printf returns -1
	char	res[20];
	ft_ftoa(69.6969, res, 10);
	printf("%s\n", res);

	// MY PRINTF
	//ft_printf("%d\n", ft_printf("%f\n", 69.42));
	return 0;
}
