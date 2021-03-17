/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:51:01 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/17 17:37:00 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	*read_map(char *path)
{
	int		fd;
	int		size;
	int		i;
	char	tmp[1];
	char	*map;

	size = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	while (read(fd, tmp, 1) > 0)
		size++;
	close(fd);
	if (size < 4)
		return (0);
	map = (char *)malloc(sizeof(char) * size + 1);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	i = -1;
	while (read(fd, tmp, 1) > 0)
		map[++i] = *tmp;
	close(fd);
	map[size] = 0;
	return (map);
}
