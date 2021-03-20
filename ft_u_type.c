/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:42:09 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:50:37 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_u(unsigned int c)
{
	int len;

	len = 1;
	while (c / 10 != 0)
	{
		c /= 10;
		++len;
	}
	return (len);
}

int		ft_space(t_parser *parser, int c_len)
{
	int len;

	if (c_len < parser->precision)
		c_len = parser->precision;
	len = parser->width - c_len;
	if (len > 0)
		ft_print((parser->flags & FLG_ZERO
		&& (parser->precision <= 0)) ? '0' : ' ', len);
	if (len > 0)
		return (len);
	return (0);
}

int		ft_zero_u(t_parser *parser, int c_len)
{
	int len;

	len = parser->precision - c_len;
	if (len > 0)
		ft_print('0', len);
	if (len > 0)
		return (len);
	return (0);
}

int		ft_put_u(unsigned int c)
{
	if (c / 10 != 0)
	{
		ft_put_u(c < 0 ? -(c / 10) : c / 10);
	}
	ft_print((c < 0) ? -(c % 10) + '0' : c % 10 + '0', 1);
	return (0);
}

int		ft_u_type(t_parser *parser, va_list *ap)
{
	int				length;
	unsigned int	c;
	int				c_len;

	length = 0;
	c = va_arg(*ap, unsigned int);
	c_len = ft_u(c);
	if (parser->precision == 0 && c == 0)
		c_len = 0;
	length = c_len;
	if ((parser->flags & FLG_MINUS) == 0)
		length += ft_space(parser, c_len);
	length += ft_zero_u(parser, c_len);
	if (!(parser->precision == 0 && c == 0))
		ft_put_u(c);
	if (parser->flags & FLG_MINUS)
		length += ft_space(parser, c_len);
	return (length);
}
