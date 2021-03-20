/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:54:01 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:59:06 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parser_width(const char *format, t_parser *parser, va_list *ap)
{
	int i;

	i = 0;
	parser->width = 0;
	if (*format == '*')
	{
		i++;
		parser->width = va_arg(*ap, int);
		if (parser->width < 0)
		{
			parser->flags |= FLG_MINUS;
			parser->width *= (-1);
		}
		parser->length++;
	}
	else
	{
		parser->width = ft_atoi((char *)format);
		while (format[i] && format[i] >= '0' && format[i] <= '9')
		{
			i++;
			parser->length++;
		}
	}
	return (i);
}
