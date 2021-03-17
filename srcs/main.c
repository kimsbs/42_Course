/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:26:38 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/17 17:13:20 by tjeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_matrix(char *map, int line)
{
	int i;

	free(map);
	i = -1;
	while (++i < line)
	{
		free(g_matrix[i].data);
		free(g_matrix[i].depth);
	}
	free(g_matrix);
	free(g_find);
}

int		main(int argc, char **argv)
{
	int i;

	if (argc < 2)
	{
		stdinput();
		system("Leaks BSQ");
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		if (i != 1)
			write(1, "\n", 1);
		doing(argv[i]);
	}
	system("Leaks BSQ");
}
