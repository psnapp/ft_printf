/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:54:40 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:36:39 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_parser(const char *format, va_list *ap, t_parser *parser)
{
	int length;

	length = 0;
	parser_flags(format, parser);
	parser_width(&format[parser->length], parser, ap);
	parser->precision = -1;
	if (format[parser->length] == '.')
	{
		parser->length++;
		if ((format[parser->length] >= '0' && format[parser->length] <= '9')
			|| (format[parser->length] == '*'))
			parser_precision(&format[parser->length], parser, ap);
		else
			parser->precision = 0;
	}
	if (!(parser_type(&format[parser->length], parser)))
		return (0);
	length = length + ft_processor(ap, parser);
	return (length);
}
