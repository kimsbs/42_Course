/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:13 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:51:15 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_game *game)
{
	int	move;

	move = -1;
	while (++move < game->height)
		free(game->map[move]);
	free(game->map);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

static int	drawing(t_game *game)
{
	char	*tmp;

	if (++game->enemy_movement == 400)
		game->enemy_movement = 0;
	game->enemy.ptr = game->link.enemy[game->enemy_movement / 100].ptr;
	print_map(game);
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
	if (game->exit_cnt == 0)
		exit_game(game);
	if (game->enemy_cnt && (game->player_x == game->enemy_x
			&& game->player_y == game->enemy_y))
		exit_game(game);
	return (0);
}

void	using_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_handler("mlx_init failed");
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "So_long");
	if (!game->win)
		exit_handler("mlx_new_window failed");
	resource_init(game);
	mlx_key_hook(game->win, deal_key, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
	mlx_loop_hook(game->mlx, &drawing, game);
	mlx_loop(game->mlx);
}
