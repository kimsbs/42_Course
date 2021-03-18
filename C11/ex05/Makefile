# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 10:14:51 by seungyki          #+#    #+#              #
#    Updated: 2021/03/17 11:14:00 by seungyki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRCS = srcs/main.c srcs/op.c srcs/ft_func.c

OBJS = $(SRCS:.c=.o)

INCLUDE = includes

all: $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I $(INCLUDE)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror -o $@ $^

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
