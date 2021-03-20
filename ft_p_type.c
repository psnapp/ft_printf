/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:41:57 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:47:25 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_p(unsigned long long int c)
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

int		ft_space_p(t_parser *parser, int c_len)
{
	int len;

	if (c_len - 2 < parser->precision + 2)
		c_len = parser->precision + 2;
	len = parser->width - c_len;
	if (len > 0)
		ft_print(' ', len);
	if (len > 0)
		return (len);
	return (0);
}

int		ft_zero_p(t_parser *parser, int c_len)
{
	int len;

	write(1, "0x", 2);
	if (parser->precision > 0)
	{
		len = parser->precision - c_len + 2;
		if (len > 0)
			ft_print('0', len);
		if (len > 0)
			return (len);
	}
	return (0);
}

int		ft_put_p(unsigned long long int c, t_parser *parser)
{
	const char	str[] = "0123456789abcdef";

	if (c / 16 != 0)
		ft_put_p(c < 0 ? -(c / 16) : c / 16, parser);
	ft_print((c < 0) ? -(str[c % 16]) : str[c % 16], 1);
	return (0);
}

int		ft_p_type(va_list *ap, t_parser *parser)
{
	int						length;
	int						c_len;
	unsigned long long int	c;

	length = 0;
	c = va_arg(*ap, unsigned long long int);
	c_len = ft_p(c) + 2;
	if (parser->precision == 0 && c == 0)
		c_len = 2;
	length = c_len;
	if ((parser->flags & FLG_MINUS) == 0)
		length += ft_space_p(parser, c_len);
	length += ft_zero_p(parser, c_len);
	if (!(parser->precision == 0 && c == 0))
	{
		ft_put_p(c, parser);
	}
	if (parser->flags & FLG_MINUS)
		length += ft_space_p(parser, c_len);
	return (length);
}
