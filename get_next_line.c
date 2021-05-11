/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:51:46 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/11 17:39:12 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		is_nextline(char *s)
{
	int move;

	move = 0;
	while (s[move])
	{
		if (*s == '\n')
			return (move);
		move++;
	}
	return (0);
}

static	char	*save_buffer(t_list *header, int how_many_read, int dummy)
{
	char	*tmp;
	int		move;
	int		tmp_move;

	tmp = (char *)malloc(sizeof(char) * ((how_many_read - 1) *
				BUFFER_SIZE + dummy + 1));
	tmp_move = 0;
	while (header)
	{
		move = -1;
		while (++move < BUFFER_SIZE)
		{
			tmp[tmp_move] = header->content[move];
			tmp_move++;
		}
		header = header->next;
	}
	//tmp[tmp_move] = '\0';

	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	int		how_many_read;
	int		rd_len;
	int		tmp;
	char	*buf;
	t_list	*header;

	header = NULL;
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	how_many_read = 0;
	while ((rd_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		how_many_read++;
		ft_lstadd_back(&header, buf);
		if ((tmp = is_nextline(buf)))
		{
			*line = save_buffer(header, how_many_read, tmp);
			return (1);
		}
	}
	free(buf);
	if (rd_len == 0)
		return (0);
	else
		return (-1);
}
