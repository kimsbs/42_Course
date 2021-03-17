/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:28:08 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/17 19:48:51 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	stdinput(void)
{
	int		fd;
	char	tmp[1];
	char	*title;

	title = "stdin_map";
	fd = open(title, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	while (read(0, tmp, 1) > 0)
		write(fd, tmp, 1);
	close(fd);
	doing(title);
}

void	doing(char *title)
{
	char	*map;
	int		line_cnt;
	int		hor_cnt;

	if (!(map = read_map(title)))
	{
		write(2, ERR_MSG, ERR_SIZE);
		return ;
	}
	line_cnt = infocheck(map);
	hor_cnt = boxcheck(map, line_cnt, 0);
	if (line_cnt < 0 || hor_cnt < 0)
	{
		free(map);
		write(2, ERR_MSG, ERR_SIZE);
		return ;
	}
	make_matrix(line_cnt, hor_cnt);
	init_matrix(line_cnt, hor_cnt, map);
	g_x = 0;
	g_y = 0;
	g_max = 0;
	solve(line_cnt, hor_cnt, 0, 0);
	free_matrix(map, line_cnt);
}
