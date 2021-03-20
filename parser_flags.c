/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:46:48 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:55:27 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parser_flags(const char *format, t_parser *parser)
{
	int	i;

	i = 0;
	parser->length = 0;
	parser->flags = FLG_NONE;
	while (*format)
	{
		if (*format == '-')
			parser->flags |= FLG_MINUS;
		else if (*format == '+')
			parser->flags |= FLG_PLUS;
		else if (*format == ' ')
			parser->flags |= FLG_SPACE;
		else if (*format == '#')
			parser->flags |= FLG_HASH;
		else if (*format == '0')
			parser->flags |= FLG_ZERO;
		else
			break ;
		format++;
		i++;
	}
	parser->length += i;
	return (i);
}
