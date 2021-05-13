/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:48:11 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/13 19:50:15 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		is_next_line(char *s)
{
	int		move;

	if (!s)
		return (-1);
	move = 0;
	while (s[move])
	{
		if (s[move] == '\n')
			return (move);
		move++;
	}
	return (-1);
}

int		split_and_done(char **sol, char **line, int next_line_whenence)
{
	int		move;
	int		sol_len;
	char	*output;

	output = (char *)malloc(sizeof(char) * (next_line_whenence + 1));
	sol_len = ft_strlen(*sol);
	move = -1;
	while (++move < next_line_whenence)
		output[move] = (*sol)[move];
	output[move++] = '\0';
	*line = output;
	if(move < sol_len)
		*sol = &(*sol)[move];
	else
		*sol = NULL;
	return (1);
}

int		free_sol(char *sol, char **line, int return_data)
{
	if (sol != NULL)
	{
		*line = ft_strdup(sol);
		free(sol);
		return (0);
	}
	return (return_data);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static	char	*sol[OPEN_MAX];
	int				rd_len;
	int				next_line_whenece;

	if (fd <= 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rd_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_len] = '\0';
		sol[fd] = ft_strjoin(sol[fd], buf);
		printf("%s\n", sol[fd]);
		if ((next_line_whenece = is_next_line(sol[fd])) >= 0)
		{
			free(buf);
			return (split_and_done(&sol[fd], line, next_line_whenece));
		}
	}
	free(buf);
	if (rd_len == 0)
		if ((next_line_whenece = is_next_line(sol[fd])) >= 0)
			return (split_and_done(&sol[fd], line, next_line_whenece));
		else
			return (free_sol(sol[fd], line, 0));
	else
		return (free_sol(sol[fd], line, -1));
}
