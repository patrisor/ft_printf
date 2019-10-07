/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patrisor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:26:03 by patrisor          #+#    #+#             */
/*   Updated: 2019/09/04 04:22:14 by patrisor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

// NOTE: inline keyword inserts the function code at the address of each function call, 
// thereby saving the overhead of a function call
// All Functions have extern keyword applied to them, but it's hidden

/* CONVERSION FLAGS
 * fF : The argument is printed in the style `[-]ddd.ddd' where the number of d's after the decimal
        point is equal to the precision specification for the argument.  If the precision is miss-
        ing, 6 digits are given; if the precision is explicitly 0, no digits and no decimal point
        are printed.  The values infinity and NaN are printed as `inf' and `nan', respectively.
 * eE : The argument is printed in the style e `[-d.ddd+-dd]' where there is one digit before the
		decimal point and the number after is equal to the precision specification for the argu-
		ment; when the precision is missing, 6 digits are produced.  The values infinity and NaN
		are printed as `inf' and `nan', respectively.
 * gG : The argument is printed in style f (F) or in style e (E) whichever gives full precision in
        minimum space.
 * aA : The argument is printed in style `[-h.hhh+-pd]' where there is one digit before the hexa-
        decimal point and the number after is equal to the precision specification for the argu-
        ment; when the precision is missing, enough digits are produced to convey the argument's
        exact double-precision floating-point representation.  The values infinity and NaN are
        printed as `inf' and `nan', respectively.
 * c : The first byte of argument is printed.
 * s : Bytes from the string argument are printed until the end is reached or until the number of
       bytes indicated by the precision specification is reached; however if the precision is 0 or
       missing, the string is printed entirely.
 * d, i : int
 * o, u, x, X : The unsigned int argument is converted to unsigned octal (o), unsigned decimal (u), 
 * or unsigned hexadecimal (x and X) notation. The letters abcdef are used for x conversions; the 
 * letters ABCDEF are used for X conversions. The precision, if any, gives the minimum number of 
 * digits that must appear; if the converted value requires fewer digits, it is padded on the left 
 * with zeros. The default precision is 1. When 0 is printed with an explicit precision 0, the output 
 * is empty.
 * p : The void * pointer argument is printed in hexadecimal
 * n : The number of characters written so far is stored into the integer indicated by the int * 
 * (or variant) pointer argument. No argument is converted.
 */
inline extern int			pf_is_conversion(const char c)
{
	return (pf_strchr("dDioOuUxXeEfFgGaAcCsSpn%", c) != NULL);
}

// Length Modifiers indicate to the standard library function (not the compiler) that you want the 
// associated argument to be interpreted as a certain type
/* h : short int (2 bytes)
 * l : long int (8 bytes)
 * j : intmax
 * z : size_t
 */
inline extern int			pf_is_modifier(const char c)
{
	return (pf_strchr("hljz", c) != NULL);
}

/* 0 : Zero padding. For all conversions except n, the converted value is padded on the left with 
 * zeros rather than blanks. If a precision is given with a numeric conversion 
 * (d, i, o, u, i, x, and X), the 0 flag is ignored.
 */
inline extern int			pf_is_flag(const char c)
{
	return (pf_strchr("#0-+' ", c) != NULL);
}

// A field width or precision may be `*' instead of a digit string.  In this 
// case an argument supplies the field width or precision.
/*
 * '.' : pads the converted number with leading zeroes up to the number after point.
 */
inline extern int			pf_is_precision(const char c)
{
	return (pf_strchr("$*.", c) != NULL);
}

// If there are any flags found in the parsing, it will return a 1.
inline int					pf_is_valid(const char c)
{
	return (pf_is_conversion(c) || pf_is_modifier(c) || pf_is_flag(c) ||
			pf_isdigit(c) || pf_is_precision(c));
}
