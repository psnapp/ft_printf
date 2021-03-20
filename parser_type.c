/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:09:01 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:58:14 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		parser_type(const char *format, t_parser *parser)
{
	char	*str;
	int		i;

	parser->type = 0;
	i = 0;
	str = "cspdiuxX%";
	while (str[i])
	{
		if (*format == str[i])
			parser->type = str[i];
		i++;
	}
	return (1);
}
