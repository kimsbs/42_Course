/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:48 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:56:17 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	map_init(char *map_name, t_game *game)
{
	int	fd;

	fd = open(map_name, O_RDONLY, 0600);
	if (fd <= 0)
		exit_handler("File open failed");
	read_map(fd, game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_handler("Usage: ./so_long [MAP_FILE.ber]");
	map_init(argv[1], &game);
	using_mlx(&game);
	return (0);
}
