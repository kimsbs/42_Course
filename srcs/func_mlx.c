#include "../includes/so_long.h"

void	exit_game(t_game *game)
{
	int move;

	move = -1;
	while(++move < game->height)
		free(game->map[move]);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static int	drawing(t_game *game)
{
	char *tmp;

	print_map(game, 1);
	print_map(game, 0);
	tmp = ft_itoa(game->move_cnt);
	mlx_string_put(game->mlx, game->win, 20, 30, 0x00FFFFFF, tmp);
	free(tmp);
	return (0);
}

int	deal_key(int key, t_game *game)
{
	if (key == 53)
		exit_game(game);
	game->animation++;
	if (key == 13 || key == 126)
		move_to_north(game);
	else if (key == 0 || key == 123)
		move_to_west(game);
	else if (key == 1 || key == 125)
		move_to_south(game);
	else if (key == 2 || key == 124)
		move_to_east(game);
	drawing(game);
	if (game->exit_cnt == 0)
		exit_game(game);
	return (0);
}

int	exit_with_mouse(t_game *game)
{
	exit_game(game);
	return (0);
}

void	using_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_handler("mlx_init failed\n");
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "So_long");
	if (!game->win)
		exit_handler("mlx_new_window fialed\n");
	resource_init(game);
	drawing(game);
	mlx_key_hook(game->win, deal_key, game);
	mlx_hook(game->win, 17, 0, exit_with_mouse, game);
	mlx_loop(game->mlx);
}
