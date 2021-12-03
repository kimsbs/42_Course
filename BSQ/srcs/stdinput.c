/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdinput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:28:08 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/17 22:07:47 by tjeong           ###   ########.fr       */
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
	doing(title, 0, 0);
}

void	init(void)
{
	g_x = 0;
	g_y = 0;
	g_max = 0;
}

void	error_case2(char *map)
{
	free(g_find);
	free(map);
	write(2, ERR_MSG, ERR_SIZE);
}

void	doing(char *title, int line_cnt, int hor_cnt)
{
	char	*map;

	init();
	if (!(map = read_map(title)))
	{
		write(2, ERR_MSG, ERR_SIZE);
		return ;
	}
	if (!(g_find = extract_element(map)))
	{
		error_case2(map);
		return ;
	}
	if ((line_cnt = infocheck(map)) < 0)
	{
		error_case2(map);
		return ;
	}
	if ((hor_cnt = boxcheck(map, line_cnt, 0)) < 0)
	{
		error_case2(map);
		return ;
	}
	whole_matrix(line_cnt, hor_cnt, map);
}

void	whole_matrix(int line_cnt, int hor_cnt, char *map)
{
	make_matrix(line_cnt, hor_cnt);
	init_matrix(line_cnt, hor_cnt, map);
	solve(line_cnt, hor_cnt, 0, 0);
	free_matrix(map, line_cnt);
}
