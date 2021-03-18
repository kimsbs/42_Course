/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyolee <yong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 18:01:47 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/14 22:25:22 by hyempark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	char	*name;
	char	*nb;
	int		len;

	name = "numbers.dict";
	if (argc == 2)
		len = make_dic(name);
	else if (argc == 3)
		len = make_dic(argv[1]);
	else
	{
		write(2, ERROR_MSG1, E1_MSG);
		return (0);
	}
	if (!len)
		return (0);
	nb = trim_unsigned_int(argv[argc - 1]);
	if (nb && g_len > 0)
	{
		ft_putnbr(nb);
		write(1, "\n", 1);
	}
	else
		write(2, ERROR_MSG1, E1_MSG);
	free_dict();
}

void	free_dict(void)
{
	int	i;

	i = 0;
	while (i < g_len)
	{
		free(g_dict[i].name);
		free(g_dict[i].nb);
		i++;
	}
	free(g_dict);
}
