/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:42:06 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:49:01 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_print_s(int c, int n)
{
	int length;

	length = 0;
	while (n--)
	{
		write(1, &c, 1);
		length++;
	}
	return (length);
}

int		ft_s_type(va_list *ap, t_parser *parser)
{
	char	*str;
	int		len;
	int		length;

	str = va_arg(*ap, char *);
	if (str == 0)
		str = "(null)";
	len = strlen(str);
	length = len;
	if (parser->precision < -1)
		parser->precision = -1;
	if (parser->precision != -1 && len > parser->precision)
	{
		len = parser->precision;
		length = len;
	}
	if ((parser->flags & FLG_MINUS) == 0 && parser->width > 0
		&& parser->width > len)
		length += ft_print_s((parser->flags & FLG_ZERO)
		? '0' : ' ', parser->width - len);
	write(1, str, len);
	if (parser->flags & FLG_MINUS && parser->width > len)
		length += ft_print_s(' ', parser->width - len);
	return (length);
}
