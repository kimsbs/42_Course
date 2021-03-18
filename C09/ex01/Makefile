NAME = libft.a

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c\
	   srcs/ft_strlen.c srcs/ft_swap.c

OBJS = $(SRCS:.c=.o)

INCLUDE = includes/

all:  $(NAME)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $< -o $@ -I $(INCLUDE)

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

