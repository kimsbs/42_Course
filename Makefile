NAME = so_long
SRCS = srcs/ft_split.c srcs/ft_strjoin.c srcs/func_error.c\
	   srcs/func_map.c srcs/main.c
MLX = mlx
MLX_lib = -L mlx -lmlx
INCLUDES = -I includes -I $(MLX)
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(MLX)
	gcc $(CFLAGS) -o $@ $(MLX_lib) $(OBJS)

clean:
	rm -f $(OBJS)
	@make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)

re: fclean all