/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyolee <yong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:37:10 by jaeyolee          #+#    #+#             */
/*   Updated: 2021/03/14 22:19:34 by hyempark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		input_str(char *tmp, int i)
{
	int	size;
	int	move;

	size = 0;
	move = -1;
	while (tmp[++move] != '\n')
		size++;
	g_dict[i].name = (char *)malloc(sizeof(char) * (size + 1));
	move = -1;
	while (tmp[++move] != '\n')
		g_dict[i].name[move] = tmp[move];
	g_dict[i].name[move] = 0;
	return (size);
}

void	write_num(char *tmp, int i, int *flag)
{
	char	*chunk;

	chunk = trim_unsigned_int(tmp);
	if (*chunk)
	{
		g_dict[i].nb = chunk;
		*flag = 1;
	}
}

int		fill_dic(char *tmp, int is_input, int flag)
{
	int	i;

	i = 0;
	while (*tmp)
	{
		if (!(*tmp == ' ' || *tmp == ':' || *tmp == '\n'))
		{
			if (flag == 0)
				write_num(tmp, i, &flag);
			else if (is_input == 0 && flag == 1)
			{
				tmp += input_str(tmp, i);
				is_input = 1;
				i++;
			}
			if (is_input == 1 && *tmp == '\n')
				flag = 0;
		}
		if (*tmp == ':')
			is_input = 0;
		tmp++;
	}
	return (i);
}

int		make_dic(char *name)
{
	char	*tmp;
	int		len;

	len = dict_len(name);
	if (!len)
		return (0);
	g_dict = (t_dict *)malloc(sizeof(t_dict) * len);
	tmp = (char *)malloc(sizeof(char) * (g_len + 1));
	make_tmp(tmp, name);
	g_len = fill_dic(tmp, 1, 0);
	free(tmp);
	return (len);
}
