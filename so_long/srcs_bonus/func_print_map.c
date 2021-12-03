/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_print_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:42 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/17 10:36:47 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	put_entity(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->link.tree.ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->link.tile.ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
}

static void	put_entity2(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->exit_cnt == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->link.exit.ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->link.coin.ptr, x * TILE_SIZE, y * TILE_SIZE);
	}
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			put_entity(game, x, y);
			put_entity2(game, x, y);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->player.ptr,
		game->player_x * TILE_SIZE, game->player_y * TILE_SIZE);
	if (game->enemy_cnt)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy.ptr,
			game->enemy_x * TILE_SIZE, game->enemy_y * TILE_SIZE);
}
