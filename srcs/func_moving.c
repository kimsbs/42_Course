/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_moving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:20 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/17 10:35:27 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_wall(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (1);
	else if (game->map[y][x] == 'C')
	{
		game->coin_cnt--;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'E' && game->coin_cnt == 0)
	{
		game->exit_cnt--;
		game->map[y][x] = '0';
	}
	game->move_cnt++;
	return (0);
}

void	move_to_north(t_game *game)
{
	game->player = game->link.pu[game->animation % 3];
	if (!is_wall(game, game->player_x, game->player_y - 1))
		game->player_y--;
}

void	move_to_south(t_game *game)
{
	game->player = game->link.pd[game->animation % 3];
	if (!is_wall(game, game->player_x, game->player_y + 1))
		game->player_y++;
}

void	move_to_east(t_game *game)
{
	game->player = game->link.pr[game->animation % 2];
	if (!is_wall(game, game->player_x + 1, game->player_y))
		game->player_x++;
}

void	move_to_west(t_game *game)
{
	game->player = game->link.pl[game->animation % 2];
	if (!is_wall(game, game->player_x - 1, game->player_y))
		game->player_x--;
}
