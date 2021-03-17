/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infocheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeong <tjeong@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:53:12 by tjeong            #+#    #+#             */
/*   Updated: 2021/03/17 15:54:21 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

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
		if (*tmp < 32 || *tmp > 126)
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
			return (-1);
		else
			line_count = line_count * 10 + (map[i] - '0');
	if ((tmp = extract_element(map)) == 0)
		return (-1);
	if ((same_element(tmp) < 0))
		return (-1);
	return (line_count);
}
