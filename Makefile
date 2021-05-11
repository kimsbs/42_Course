NAME = get_next_line
SRCS = get_next_line.c get_next_line_utile.c

CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJS)
	ar rc $@ $^

clean:
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
