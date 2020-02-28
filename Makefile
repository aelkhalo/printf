# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahamdaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 19:07:35 by ahamdaou          #+#    #+#              #
#    Updated: 2020/02/01 17:43:44 by aelkhalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

G = gcc -Wall -Wextra -Werror
SRC = *.c
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
