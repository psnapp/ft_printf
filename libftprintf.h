/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:46:43 by psnapp            #+#    #+#             */
/*   Updated: 2020/11/28 13:11:55 by psnapp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define FLG_NONE 0b00000000
# define FLG_MINUS 0b00000001
# define FLG_PLUS 0b00000010
# define FLG_SPACE 0b00000100
# define FLG_HASH 0b00001000
# define FLG_ZERO 0b00010000

typedef struct		s_parser
{
	char	flags;
	int		width;
	int		precision;
	char	type;
	int		length;
}					t_parser;

int					ft_printf(const char *format, ...);
int					parser_flags(const char *format, t_parser *parser);
int					parser_width(const char *format,
					t_parser *parser, va_list *ap);
int					parser_type(const char *format, t_parser *parser);
int					ft_parser(const char *format,
					va_list *ap, t_parser *parser);
int					ft_atoi(char *str);
int					parser_precision(const char *format,
					t_parser *parser, va_list *ap);
int					ft_processor(va_list *ap, t_parser *parser);
int					ft_c_type(va_list *ap, t_parser *parser);
int					ft_di_type(t_parser *parser, va_list *ap);
int					ft_percent_type(t_parser *parser);
int					ft_s_type(va_list *ap, t_parser *parser);
int					ft_u_type(t_parser *parser, va_list *ap);
int					ft_x_type(t_parser *parser, va_list *ap);
int					ft_p_type(va_list *ap, t_parser *parser);
void				ft_print(int c, int n);
int					ft_di(int c);

#endif
