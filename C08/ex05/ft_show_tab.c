/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 05:51:15 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/15 22:19:16 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_str(char *str)
{
	while (*str)
	{
		put_char(*str);
		str++;
	}
}

void	itoa(int size)
{
	if (size == 0)
		return ;
	itoa(size / 10);
	put_char(size % 10 + '0');
}

void	itoa_ready(int size)
{
	if (size == 0)
		put_char('0');
	else
		itoa(size);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = -1;
	while (par[++i].str)
	{
		print_str(par[i].str);
		put_char('\n');
		itoa_ready(par[i].size);
		put_char('\n');
		print_str(par[i].copy);
		put_char('\n');
	}
}
