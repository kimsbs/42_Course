/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyolee <yong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:20:41 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/14 22:18:31 by hyempark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		g_len;

int		dict_len(char *name)
{
	int		len;
	int		n;
	char	buf;
	int		fd;

	fd = open(name, O_RDONLY);
	len = 0;
	g_len = 0;
	if (fd == -1)
	{
		write(2, ERROR_MSG2, E2_MSG);
		exit(0);
	}
	while ((n = read(fd, &buf, 1)) > 0)
	{
		if (buf == '\n')
			len++;
		(g_len)++;
	}
	close(fd);
	return (len);
}

void	make_tmp(char *tmp, char *name)
{
	int		i;
	int		n;
	int		fd;
	char	buf;

	fd = open(name, O_RDONLY);
	i = 0;
	while ((n = read(fd, &buf, 1)) > 0)
		tmp[i++] = buf;
	tmp[i] = '\0';
	close(fd);
}

void	put_str(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		str_cmp(char *a, char *b)
{
	while (*a != '\0' && *b != '\0')
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (*a - *b);
}
