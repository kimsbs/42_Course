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
	int		i;
	int		fix;
	char	tmp[1];
	char	*element;

	i = -1;
	fix = 0;
	while (map[++i] != '\n')
		fix++;
	i = -1;
	element = (char *)malloc(4 * sizeof(char));
	while (++i < 3)
	{
		*tmp = map[++fix - 4];
		if (*tmp < 32 || *tmp >126)
			return (0);
		element[i] = *tmp;
	}
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
	char	*tmp;

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
			errp("err : line count is not a valid number\n");
		}
		else
		{line_count = line_count * 10 + (map[i] - '0');}
	if((tmp = extract_element(map)) == 0)
	{
		errp("err : NonPrintable element\n");
		return (-1);
	}
	if ((same_element(tmp) < 0))
	{
		errp("err : duplicated element\n");
		return (-1);
	}
	return (line_count);
}

int		in_element(char c, char *element)
{
	int i;

	i = -1;
	while (element[++i])
		if (c == element[i])
			return (1);
	return (-1);
}

int		horizontal_check(char *map)
{
	int i;
	int hor_std;
	int	hor_now;

	i = -1;
	hor_std = 0;
	while (map[++i] != '\n' && map[i])
		hor_std++;
	while (map[++i])
	{
		hor_now = 0;
		while (map[i] != '\n' && map[i])
		{
			hor_now++;
			i++;
		}
		if (hor_std != hor_now)
			return (-1);
	}
	return (hor_std);
}

int		boxcheck(char *map, int line_count)
{
	int		i;
	int		nl_cnt;
	int		empty_count;
	char	*element;
	int		hor_cnt;

	/* skip info line */
	i = 0;
	while (map[i] != '\n')
		i++;
	/* horizontal count inspect */
	if ((hor_cnt = horizontal_check((map + i + 1))) < -1)
	{
		errp("err : diffent horizontal count\n");
		return (-1);
	}
	/* counting [\n] And inspect element validation */
	element = extract_element(map);
	empty_count = 0;
	nl_cnt = 0;
	while (map[++i])
	{
		if (in_element(map[i], element) < 0 && map[i] != '\n')
		{
			errp("err : not perdefined box component\n");
			return (-1);
		}
		if (map[i] == '\n')
			nl_cnt++;
		if (map[i] == element[0])
			empty_count++;
	}
	if (empty_count == 0)
	{
		errp("err : no empty element\n");
		return (-1);
	}
	printf("===in boxcheck===\nactual line cnt = [%d]\n",nl_cnt);
	if (line_count != nl_cnt)
	{
		errp("err : [info line cnt], [actual line cnt] are not same\n");
		return (-1);
	}
	return (hor_cnt);
}

int		main(int ac, char **av)
{
	printf("===readmap check===\n%s\n", read_map(av[1]));
	printf("===infocheck check===\nline count : [%d]\n", infocheck(read_map(av[1])));
	printf("===element extract check===\nelement : [%s]\n", extract_element(read_map(av[1])));
	printf("===boxcheck check===\nhor_cnt : [%d]\n", boxcheck(read_map(av[1]), infocheck(read_map(av[1]))));
}
