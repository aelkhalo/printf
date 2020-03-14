# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelkhalo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/14 01:43:17 by aelkhalo          #+#    #+#              #
#    Updated: 2020/03/14 01:44:59 by aelkhalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror
SRC = d_handlers2.c ft_printf.c ft_utils.c handlers.c print_fun.c u_handlers.c x_utils.c d_handler.c ft_get_things.c ft_utils2.c p_handlers.c s_handler.c x_handlers.c
O = *.o
NAME = libftprintf.a

all: $(NAME)
	ar rc $(NAME) $(O)
	ranlib $(NAME)
	@echo $(NAME) is created

$(NAME): 
	$(G) -c $(SRC)

bonus: $(NAME)

clean: 
	rm -f $(O)

fclean: clean
	rm -f $(NAME)

re: fclean all
