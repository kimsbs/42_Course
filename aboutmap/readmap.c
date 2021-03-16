/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:26:12 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/16 02:01:43 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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
	close (fd);
	map = (char *)malloc(sizeof(char) * size + 1);
	fd = open(path, O_RDONLY);
	i = -1;
	while (read(fd, tmp, 1) > 0)
		map[++i] = *tmp;
	close (fd);
	map[size] = 0;
	return (map);
}

char	*extract_element(char *map)
{
	int i;
	int fix;
	char *element;

	i = -1;
	fix = 0;
	while (map[++i] != '\n')
		fix++;
	i = -1;
	element = (char *)malloc(4 * sizeof(char));
	while (++i < 3)
		element[i] = map[++fix - 4];
	element[i] = 0;
	return (element);
}

int		same_element(char *element)
{
	int i;
	int j;

	i = -1;
	while (element[++i])
	{
		j = i;
		while (element[++j])
			if (element[i] == element[j])
				return (-1);
	}
	return (1);
}

int		infocheck(char *map)
{
	int		i;
	int		line_count;
	int		fix;

	i = -1;
	fix = 0;
	while (map[++i] != '\n')
		fix++;
	i = -1;
	line_count = 0;
	while (++i < (fix - 3))
		if (map[i] < '0' || map[i] > '9')
		{
			return (-1);
			printf("err : line count is not number\n");
		}
		else
		{line_count = line_count * 10 + (map[i] - '0');}

	if ((same_element(extract_element(map)) < 0))
	{
		printf("err : duplicated element err\n");
		return (-1);
	}
	return (line_count);
}

int		boxcheck(char *map, int line_count)
{
	int		i;
	int		fix;
	int		tmp;
	char	*element;

	element = extract_element(map);
	i = 0;
	while (map[i] != '\n')
		i++;
	tmp = 0;
	while (map[++i])
		if (map[i] == '\n')
			tmp++;
	if (line_count != tmp)
	{
		printf("err : invalid line count\n");
		return (-1);
	}

	return (0);
}

int		main(int ac, char **av)
{
	printf("===readmap check===\n%s\n", read_map(av[1]));
	printf("===infocheck check===\nline count : [%d]\n", infocheck(read_map(av[1])));
	printf("===element extract check===\nelement : [%s]\n", extract_element(read_map(av[1])));
}
