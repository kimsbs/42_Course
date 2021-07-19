NAME	=	push_swap
CC		=	cc
SRCS	=	func_atob.c	func_btoa.c func_free.c func_list.c \
			func_print.c func_push.c func_rev.c func_rot.c \
			func_short_swap.c func_sort.c func_swap.c main.c \
			func_three.c func_five.c func_short_swap2.c

OBJ		=	$(SRCS:.c=.o)
CFLAGS	=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

$(OBJ):		$(SRCS)
			$(CC) -c $(CFLAGS) $(SRCS)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean re fclean