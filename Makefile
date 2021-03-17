NAME = BSQ
SRCS = srcs/about_matrix.c srcs/infocheck.c srcs/print_matrix.c\
	   srcs/stdinput.c srcs/boxcheck.c srcs/readmap_util.c\
	   srcs/main.c
INCLUDES = includes
CFLAGS = -Wall -Wextra -Werror -g3
OBJS = $(SRCS:.c=.o)
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
