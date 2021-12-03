NAME = so_long
NAME_BONUS = so_long_bonus
SRCS = srcs/ft_split.c srcs/ft_strjoin.c srcs/func_error.c\
	   srcs/func_map.c srcs/main.c srcs/func_mlx.c srcs/func_init.c\
	   srcs/func_moving.c srcs/func_print_map.c srcs/ft_itoa.c
SRCS_BONUS = srcs_bonus/ft_split.c srcs_bonus/ft_strjoin.c srcs_bonus/func_error.c\
	   srcs_bonus/func_map.c srcs/main.c srcs_bonus/func_mlx.c srcs_bonus/func_init.c\
	   srcs_bonus/func_moving.c srcs_bonus/func_print_map.c srcs_bonus/ft_itoa.c
MLX = mlx
MLX_lib = -Lmlx -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I includes -I $(MLX)
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@ $(INCLUDES)

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME):$(OBJS)
	@make -C $(MLX)
	gcc $(CFLAGS) -o $@ $(MLX_lib) $(OBJS)

$(NAME_BONUS):$(OBJS_BONUS)
	@make clean -C $(MLX)
	@make -C $(MLX)
	gcc $(CFLAGS) -o $@ $(MLX_lib) $(OBJS_BONUS)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	@make clean -C $(MLX)
	
re: fclean all
