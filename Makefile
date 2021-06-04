# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/20 11:53:16 by seungyki          #+#    #+#              #
#    Updated: 2021/06/04 19:16:06 by seungyki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c	func1.c func_int.c func_str.c func_flag.c\
	   print_option.c func2.c func3.c func4.c func5.c\
	   func_char.c

CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
