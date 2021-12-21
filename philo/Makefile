NAME = philo
NAME_BONUS = philo_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = main\
	ft_func\
	error\
	init_data\
	get_fork\
	philo_function

FILE_BONUS = main\
	ft_func\
	error\
	init_data\
	get_fork\
	philo_function

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE))) 
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE))) 

SRCS_BONUS_DIR = ./srcs_bonus/
SRCS_BONUS = $(addprefix $(SRCS_BONUS_DIR), $(addsuffix .c, $(FILE))) 
OBJS_BONUS_DIR = ./srcs_bonus/
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR), $(addsuffix .o, $(FILE))) 

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: clean all

.PHONY: all bonus clean fclean re
