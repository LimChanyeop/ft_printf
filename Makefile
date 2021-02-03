# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:20:34 by clim              #+#    #+#              #
#    Updated: 2021/02/03 11:55:24 by clim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = *.c

OBJECTS = *.o

LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS) : $(SRCS) $(LIB)
	gcc -Wextra -Werror -Wall -c -g -I . $(LIB) $(SRCS)
	make -C ./libft all
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	make -C ./libft clean

fclean: clean
	rm -rf $(NAME)
	rm -rf *.gch

test:
	gcc main.c -L. -lftprintf

re: fclean all
