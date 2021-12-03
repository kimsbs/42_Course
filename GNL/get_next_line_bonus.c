/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:48:11 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/14 15:37:28 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		is_next_line(char *s)
{
	int		move;

	move = 0;
	while (s[move])
	{
		if (s[move] == '\n')
			return (move);
		move++;
	}
	return (-1);
}

int		split_and_done(char **sol, char **line, int next_line_whenence,
		char *buf)
{
	int		left_len;
	char	*left;

	if (buf)
		free(buf);
	(*sol)[next_line_whenence] = '\0';
	left_len = ft_strlen(*sol + next_line_whenence + 1);
	*line = ft_strdup(*sol);
	if (left_len == 0)
	{
		free(*sol);
		*sol = 0;
		return (1);
	}
	left = ft_strdup(*sol + next_line_whenence + 1);
	free(*sol);
	if (!left)
		return (-1);
	*sol = left;
	return (1);
}

int		while_is_over(char **sol, char **line, int rd_len)
{
	int		next_line_whenece;

	if (rd_len < 0)
		return (-1);
	if (*sol && (next_line_whenece = is_next_line(*sol)) >= 0)
		return (split_and_done(sol, line, next_line_whenece, 0));
	else if (*sol)
	{
		*line = *sol;
		*sol = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char			*buf;
	static	char	*sol[OPEN_MAX];
	int				rd_len;
	int				next_line_whenece;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((rd_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[rd_len] = '\0';
		sol[fd] = ft_strjoin(sol[fd], buf);
		if ((next_line_whenece = is_next_line(sol[fd])) >= 0)
			return (split_and_done(&sol[fd], line, next_line_whenece, buf));
	}
	free(buf);
	return (while_is_over(&sol[fd], line, rd_len));
}
