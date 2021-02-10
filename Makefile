# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clim <clim@student.42seoul.kr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/28 14:20:34 by clim              #+#    #+#              #
#    Updated: 2021/02/10 13:44:44 by clim             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
		handle_c.c \
		handle_option.c \
		handle_d_i.c \
		handle_p.c \
		handle_pct.c \
		handle_s.c \
		handle_u.c \
		handle_x.c \
		util.c

OBJECTS = $(SRCS:%.c=%.o)

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

test1:
	gcc main1.c -L. -lftprintf

re: fclean all
