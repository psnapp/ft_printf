/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:41:53 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 13:09:23 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_space_di(t_parser *parser, int c_len, int z)
{
	int len;

	if (c_len < parser->precision)
		c_len = parser->precision;
	len = parser->width - c_len;
	if (len > 0)
	{
		if (z != 0 && parser->flags & FLG_ZERO &&
		(parser->precision <= 0) && !(parser->flags & FLG_MINUS))
			write(1, "-", 1);
		ft_print((parser->flags & FLG_ZERO && (parser->precision <= 0)
		&& !(parser->flags & FLG_MINUS)) ? '0' : ' ', len - z);
	}
	if (len == 0 && z && (parser->flags & FLG_ZERO))
		write(1, "-", 1);
	if (len > 0)
		return (len - z);
	return (0);
}

int		ft_zero_di(t_parser *parser, int c_len)
{
	int len;

	len = parser->precision - c_len;
	if (len > 0)
		ft_print('0', len);
	if (len > 0)
		return (len);
	return (0);
}

int		ft_put_di(int c)
{
	if (c / 10 != 0)
	{
		ft_put_di(c < 0 ? -(c / 10) : c / 10);
	}
	ft_print((c < 0) ? -(c % 10) + '0' : c % 10 + '0', 1);
	return (0);
}

int		ft_parser_di(t_parser *parser, int z, int c_len)
{
	int length;

	length = 0;
	if ((parser->flags & FLG_MINUS) == 0)
	{
		length += ft_space_di(parser, c_len, z);
		if (z != 0 && !(parser->flags & FLG_ZERO && (parser->precision <= 0)))
			write(1, "-", 1);
	}
	else
	{
		if (z != 0)
			write(1, "-", 1);
	}
	return (length);
}

int		ft_di_type(t_parser *parser, va_list *ap)
{
	int length;
	int	c;
	int	c_len;
	int z;

	length = 0;
	z = 0;
	c = va_arg(*ap, int);
	if (c < 0)
	{
		z = 1;
		c = c * (-1);
		length++;
	}
	c_len = ft_di(c);
	if (parser->precision == 0 && c == 0)
		c_len = 0;
	length += c_len;
	length += ft_parser_di(parser, z, c_len);
	length += ft_zero_di(parser, c_len);
	if (!(parser->precision == 0 && c == 0))
		ft_put_di(c);
	if (parser->flags & FLG_MINUS)
		length += ft_space_di(parser, c_len, z);
	return (length);
}
