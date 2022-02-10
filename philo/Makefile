NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = main\
	ft_func\
	error\
	init_data\
	get_fork\
	philo_function\
	dead_monitor

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE))) 
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE))) 

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: clean all

.PHONY: all bonus clean fclean re
