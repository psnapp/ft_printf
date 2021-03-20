/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:41:41 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 11:36:44 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_percent(t_parser *parser)
{
	char	space;
	int		i;
	int		length;

	space = ' ';
	length = 0;
	write(1, "%", 1);
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

int		ft_zero(t_parser *parser)
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
	write(1, "%", 1);
	return (length);
}

int		ft_percent_type(t_parser *parser)
{
	int	length;

	length = 1;
	if (parser->flags & (FLG_MINUS) || parser->flags & (FLG_MINUS) & (FLG_ZERO))
		length += ft_percent(parser);
	else if (parser->flags & (FLG_ZERO))
		length += ft_zero(parser);
	else
	{
		if (parser->width > 0)
			length += ft_zero(parser);
		else
		{
			write(1, "%", 1);
		}
	}
	return (length);
}
