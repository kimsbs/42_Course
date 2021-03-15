/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:26:12 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/15 23:16:01 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *ft_strndup(char *str, int size)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * size + 1);
	i = -1;
	while (++i < size)
		res[i] = str[i];
	res[++i] = 0;
	return (res);
}

char	*read_map(char *path)
{
	int		fd;
	int		size;
	int		i;
	char	tmp[1];
	char	*map;

	/* newline 카운트를 하기에는 반환값반환도 못하겠고....변수개수도 부족해요.  */
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
		i++;
	close (fd);
	map[size] = 0;
	return (map);
}

/* return info_lines line_count */
int		infocheck(char *map, char *boxelement)
{
	int		i;
	int		fix;
	char 	*tmp;

	i = -1;
	fix = 0;
	while (map[++i] != \n)
		fix++;
	i = -1;
	while (++i < (fix - 3))
	{
		if (map[i] < '0' || map[i] > '9')
			return (-1);

	}
	while (map[++i] != '\n')


}


}
int		main(int ac, char **av)
{
	printf("%s\n", read_map(av[1]));

}
