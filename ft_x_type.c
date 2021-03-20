/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:42:12 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:59:58 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_x(unsigned int c)
{
	int len;

	len = 1;
	while (c / 16 != 0)
	{
		c /= 16;
		++len;
	}
	return (len);
}

int		ft_space_x(t_parser *parser, int c_len)
{
	int len;

	if (c_len < parser->precision)
		c_len = parser->precision;
	len = parser->width - c_len;
	if (len > 0)
		ft_print((parser->flags & FLG_ZERO &&
		(parser->precision <= 0)) ? '0' : ' ', len);
	if (len > 0)
		return (len);
	return (0);
}

int		ft_zero_x(t_parser *parser, int c_len)
{
	int len;

	len = parser->precision - c_len;
	if (len > 0)
		ft_print('0', len);
	if (len > 0)
		return (len);
	return (0);
}

int		ft_put_x(unsigned int c, t_parser *parser)
{
	const char	str[] = "0123456789abcdef";
	const char	str1[] = "0123456789ABCDEF";

	if (c / 16 != 0)
	{
		ft_put_x(c < 0 ? -(c / 16) : c / 16, parser);
	}
	if (parser->type == 'x')
		ft_print((c < 0) ? -(str[c % 16]) : str[c % 16], 1);
	else
		ft_print((c < 0) ? -(str1[c % 16]) : str1[c % 16], 1);
	return (0);
}

int		ft_x_type(t_parser *parser, va_list *ap)
{
	int				length;
	unsigned int	c;
	int				c_len;

	length = 0;
	c = va_arg(*ap, unsigned int);
	c_len = ft_x(c);
	if (parser->precision == 0 && c == 0)
		c_len = 0;
	length = c_len;
	if ((parser->flags & FLG_MINUS) == 0)
		length += ft_space_x(parser, c_len);
	length += ft_zero_x(parser, c_len);
	if (!(parser->precision == 0 && c == 0))
		ft_put_x(c, parser);
	if (parser->flags & FLG_MINUS)
		length += ft_space_x(parser, c_len);
	return (length);
}
