NAME = libft.a
SRCS = *.c
CFLAGS = -Wall -Wextra -Werror
OBJS = *.o
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	ar rc $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
