/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:24:34 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 21:53:51 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "frame.h"
#include "findnum.h"

int g_flag = 0;

int		firstdo(char *argv)
{
	int size;

	size = 0;
	size = find_size(argv);
	if (size % 4 != 0 || size / 4 < 4)
	{
		write(1, "Error: Inputdata fault2\n", 24);
		return (0);
	}
	return (size);
}

int		main(int argc, char **argv)
{
	int		arr[11][11];
	int		*input;
	int		size;

	if (argc == 2)
	{
		size = firstdo(argv[1]);
		if (size == 0)
			return (0);
		input = (int *)malloc(sizeof(int) * size);
		make_input(argv[1], input);
		make_metrix(arr, input, size / 4);
		if (checker(arr, size / 4))
			write(1, "Error: Inputdata fault3\n", 24);
		else
		{
			moving(arr, size / 4);
			if (g_flag == 0)
				write(1, "Error: Solution doesn't exist\n", 30);
		}
		free(input);
	}
	else
		write(1, "Error: Inputdata fault1\n", 24);
}
