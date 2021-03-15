/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:26:12 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/15 21:26:01 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>


char	*info_read(char *path, int *size)
{
	int		i;
	int		fd;
	char	tmp[1];
	char	*info_line;

	fd = open(path, O_RDONLY);
	*size = 0;
	while (read(fd, tmp, 1) > 0 && *tmp != '\n')
		*size++;
	close (fd);
	info_line = (char *)malloc(sizeof(char) * (*size) + 1);
	fd = open(av[1], O_RDONLY);
	read(fd, info_line, *size);
	close(fd);
	info_line[*size] = 0;
	return (info_line);
}

int		info_check(char *path, char *boxinfo, char *countinfo)
{
	int		i;
	int		size;
	char	*info_line;

	info_line = info_read(path ,&size);
	i = -1;
	while (++i < size - 3)
		if (info_line[i] > '0' || info_line[i] < '9')
			return (-1);
	i = -1;




	return (1);
}

int		total_check(char *path)
{
	int fd;
	char boxinfo[3];
	char *countinfo;

	fd = open(av[1], O_RDONLY);
	if (info_check(path) < 0)
		return (-1);
}

int		main(int ac, char **av)
{

}
