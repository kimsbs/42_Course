NAME = rush-02
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/ft_numconvert.c srcs/make_dict.c srcs/setting.c srcs/trim.c srcs/about_print.c
OBJS = $(SRCS:.c=.o)
INCDIR = includes

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
