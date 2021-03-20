/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:55:11 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:39:06 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_processor(va_list *ap, t_parser *parser)
{
	char	type;
	int		length;

	type = parser->type;
	if (type == 'c')
		length = ft_c_type(ap, parser);
	if (type == 's')
		length = ft_s_type(ap, parser);
	if (type == 'p')
		length = ft_p_type(ap, parser);
	if (type == 'd' || type == 'i')
		length = ft_di_type(parser, ap);
	if (type == 'u')
		length = ft_u_type(parser, ap);
	if (type == 'x' || type == 'X')
		length = ft_x_type(parser, ap);
	if (type == '%')
		length = ft_percent_type(parser);
	return (length);
}
