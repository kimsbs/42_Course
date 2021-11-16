#include "../includes/so_long.h"

int	is_wall(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		return (0);
	else if (game->map[y][x] == 'c')
	{
		game->coin_cnt--;
		game->map[y][x] = '0';
	}
	else if (game->map[y][x] == 'e' && game->coin_cnt == 0 &&
			game->exit_cnt == 1)
	{
		game->exit_cnt--;
		game->map[y][x] = '0';
	}
	return (1);
}

void	move_to_north(t_game *game)
{
	game->move++;
	game->player = game->link.pu[game->move % 3];
	write(1, "w", 1);
	if (!is_wall(game, game->player_x, game->player_y - 1))
		return ;
	game->player_y--;
}

void	move_to_south(t_game *game)
{
	game->move++;
	game->player = game->link.pd[game->move % 3];
	write(1, "s", 1);
	if (!is_wall(game, game->player_x, game->player_y + 1))
		return ;
	game->player_y++;
}

void	move_to_east(t_game *game)
{
	game->move++;
	game->player = game->link.pr[game->move % 2];
	write(1, "d", 1);
	if (!is_wall(game, game->player_x + 1, game->player_y))
		return ;
	game->player_x++;
}

void	move_to_west(t_game *game)
{
	game->move++;
	game->player = game->link.pl[game->move % 2];
	write(1, "a", 1);
	if (!is_wall(game, game->player_x - 1, game->player_y))
		return ;
	game->player_x--;
}
