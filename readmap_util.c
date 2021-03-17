/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:51:01 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/17 15:53:52 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	errp(char *msg)
{
	int size;

	size = 0;
	while (msg[size])
		size++;
	write(2, msg, size);
}

char	*read_map(char *path)
{
	int		fd;
	int		size;
	int		i;
	char	tmp[1];
	char	*map;

	size = 0;
	fd = open(path, O_RDONLY);
	while (read(fd, tmp, 1) > 0)
		size++;
	close(fd);
	map = (char *)malloc(sizeof(char) * size + 1);
	fd = open(path, O_RDONLY);
	i = -1;
	while (read(fd, tmp, 1) > 0)
		map[++i] = *tmp;
	close(fd);
	map[size] = 0;
	return (map);
}
