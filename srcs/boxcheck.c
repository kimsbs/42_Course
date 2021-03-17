/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:44:19 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/17 19:25:17 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int		in_element(char c, char *element)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (c == element[i])
			return (1);
		i++;
	}
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

int		box_nlcheck(char *map)
{
	int		i;
	int		nl_cnt;

	i = -1;
	nl_cnt = 0;
	while (map[++i])
		if (mpa[i] == '\n')
			nl_cnt++;
	return (nl_cnt);
}

int		box_element_check(char *map, char *element)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (in_element(map[i], element) < 0 && map[i] != '\n')
			return (-1);
	}
	return (0);
}

int		boxcheck(char *map, int line_count, int i)
{
	int		nl_cnt;
	int		empty_count;
	char	*element;
	int		hor_cnt;

	while (map[i] != '\n')
		i++;
	if ((hor_cnt = horizontal_check((map + i + 1))) < -1)
		return (-1);
	nl_cnt = box_nlcheck((map + i));
	element = extract_element(map);
	if ((box_element_check((map + i), element)) < 0)
		return (-1);
	empty_count = 0;
	while (map[++i])
		if (map[i] == element[0])
			empty_count++;
	if (empty_count == 0 || line_count != nl_cnt)
	{
		free(element);
		return (-1);
	}
	g_find = element;
	return (hor_cnt);
}
