# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psnapp <psnapp@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 13:41:35 by psnapp            #+#    #+#              #
#    Updated: 2020/11/28 13:12:05 by psnapp           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

FLAG = -Wall -Wextra -Werror -c

OPTION = -c -I $(HEADER)

SRC = ft_printf.c ft_parser.c parser_flags.c parser_width.c parser_precision.c \
		ft_percent_type.c ft_atoi.c ft_c_type.c ft_di_type.c ft_p_type.c ft_s_type.c \
    	ft_u_type.c ft_x_type.c parser_type.c ft_processor.c ft_print.c ft_di.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
		gcc $(FLAG) $< -o $@

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all