/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 05:34:38 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/15 18:12:52 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					str_len(char *av)
{
	int i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

char				*str_cpy(char *av, int size)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (av[i])
	{
		tmp[i] = av[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*s_av;
	int				i;

	s_av = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!s_av)
		return (0);
	i = 0;
	while (i < ac && av[i])
	{
		s_av[i].size = str_len(av[i]);
		s_av[i].str = av[i];
		s_av[i].copy = str_cpy(av[i], s_av[i].size);
		i++;
	}
	s_av[i].size = 0;
	s_av[i].str = 0;
	s_av[i].str = 0;
	return (s_av);
}
