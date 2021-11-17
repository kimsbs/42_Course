/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:02 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:51:07 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_size(t_game *game)
{
	game->player_cnt = 0;
	game->enemy_cnt = 0;
	game->enemy_movement = 0;
	game->coin_cnt = 0;
	game->exit_cnt = 0;
	game->move_cnt = 0;
	game->animation = 0;
	game->height = -1;
	game->width = ft_strlen(game->map[0]);
	while (game->map[++game->height])
	{
		if (game->width != ft_strlen(game->map[game->height]))
			exit_handler("Map is not rectangular\n");
	}
}

static void	cheking_entity(t_game *game, int x, int y)
{
	if ((y == 0 || y == game->height - 1) && game->map[y][x] != '1')
		exit_handler("Map is not Blocked");
	else if ((x == 0 || x == game->width - 1) && game->map[y][x] != '1')
		exit_handler("Map is not Blocked");
	else if (game->map[y][x] == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		game->player_cnt++;
	}
	else if (game->map[y][x] == 'C')
		game->coin_cnt++;
	else if (game->map[y][x] == 'E')
		game->exit_cnt++;
	else if (game->map[y][x] == 'e')
	{
		game->enemy_x = x;
		game->enemy_y = y;
		game->enemy_cnt++;
	}
	else if (game->map[y][x] != '1' && game->map[y][x] != '0')
		exit_handler("Map have more than 5 characters\n");
}

static int	checking_val(t_game *game)
{
	if (game->player_x <= 0 || game->player_x >= game->width)
		return (0);
	else if (game->player_y <= 0 || game->player_y >= game->height)
		return (0);
	else if (game->player_cnt != 1)
		return (0);
	else if (game->coin_cnt <= 0)
		return (0);
	else if (game->exit_cnt != 1)
		return (0);
	else
		return (1);
}

static void	checking_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			cheking_entity(game, x, y);
		}
	}
	if (!checking_val(game))
		exit_handler("Map char error\n");
}

void	read_map(int fd, t_game *game)
{
	int		len;
	char	str[257];
	char	*tmp;

	tmp = NULL;
	len = read(fd, &str, 256);
	while (len > 0)
	{
		str[len] = '\0';
		tmp = ft_strjoin(tmp, str);
		len = read(fd, &str, 256);
	}
	if (!tmp)
		exit_handler("Map doesn't exist\n");
	game->map = ft_split(tmp, '\n');
	free(tmp);
	get_size(game);
	checking_map(game);
}
