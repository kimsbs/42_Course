/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 16:29:06 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/08 20:29:05 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int a;

	a = argc;
	while (*argv[0])
	{
		write(1, argv[0], 1);
		argv[0]++;
	}
	write(1, "\n", 1);
}
