/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 11:04:03 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 13:00:13 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parser	parser;
	int			result;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	result = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			result += ft_parser(format, &ap, &parser);
			while (*format && *format != parser.type)
				format++;
		}
		else
			result += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (result);
}
