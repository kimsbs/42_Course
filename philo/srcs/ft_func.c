/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:20:05 by ksy               #+#    #+#             */
/*   Updated: 2021/12/23 21:21:50 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	move;

	move = -1;
	while (s[++move])
	{
		ft_putchar(s[move]);
	}
}

int	ft_atoi(char *s)
{
	int	tmp;
	int	sol;
	int	cur;
	int	move;

	move = ft_strlen(s);
	cur = 1;
	sol = 0;
	while (--move >= 0)
	{
		tmp = s[move] - '0';
		tmp *= cur;
		sol += tmp;
		cur *= 10;
	}
	return (sol);
}
