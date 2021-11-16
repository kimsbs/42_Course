/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:50:49 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:50:51 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_handler(char *s1)
{
	ft_putstr(s1);
	exit(-1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	len;
	int	move;

	move = -1;
	len = ft_strlen(s);
	while (++move < len)
	{
		ft_putchar(s[move]);
	}
}
