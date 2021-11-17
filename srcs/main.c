/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:51:48 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:51:50 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_init(char *map_name, t_game *game)
{
	int	fd;

	fd = open(map_name, O_RDONLY, 0600);
	if (fd <= 0)
		exit_handler("File open failed\n");
	read_map(fd, game);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_handler("Usage: ./so_long [MAP_FILE.ber]\n");
	map_init(argv[1], &game);
	using_mlx(&game);
	return (0);
}
