/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:10:04 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:37:38 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parser_precision(const char *format, t_parser *parser, va_list *ap)
{
	int i;

	i = 0;
	parser->precision = -1;
	parser->length++;
	i++;
	if (*format == '*')
	{
		i++;
		parser->precision = va_arg(*ap, int);
		if (parser->width < 0)
		{
			parser->precision = 0;
		}
	}
	else
	{
		parser->precision = ft_atoi((char *)format);
		while (format[i] && format[i] >= '0' && format[i] <= '9')
		{
			i++;
			parser->length++;
		}
	}
	return (i);
}
