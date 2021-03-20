/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:41:48 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:31:13 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_c(unsigned char c, t_parser *parser)
{
	char	space;
	int		i;
	int		length;

	space = ' ';
	length = 1;
	write(1, &c, 1);
	if (parser->width > 0)
	{
		i = parser->width - 1;
		while (i > 0)
		{
			write(1, &space, 1);
			i--;
			length++;
		}
	}
	return (length);
}

int		ft_c_zero(unsigned char c, t_parser *parser)
{
	int i;
	int length;

	length = 0;
	if (parser->width > 0)
	{
		i = parser->width - 1;
		while (i > 0)
		{
			if (parser->flags & FLG_ZERO)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			i--;
			length++;
		}
	}
	write(1, &c, 1);
	length++;
	return (length);
}

int		ft_c_type(va_list *ap, t_parser *parser)
{
	unsigned char	c;
	int				length;

	c = va_arg(*ap, int);
	length = 0;
	if (parser->flags & (FLG_MINUS) || parser->flags & (FLG_MINUS) & (FLG_ZERO))
		length += ft_c(c, parser);
	else if (parser->flags & (FLG_ZERO))
		length += ft_c_zero(c, parser);
	else
	{
		if (parser->width > 0)
			length += ft_c_zero(c, parser);
		else
		{
			write(1, &c, 1);
			length++;
		}
	}
	return (length);
}
