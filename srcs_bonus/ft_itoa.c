/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:50:21 by seungyki          #+#    #+#             */
/*   Updated: 2021/11/16 17:54:43 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	put_num(char *s, int num, int len)
{
	while (--len >= 0)
	{
		s[len] = num % 10 + '0';
		num /= 10;
	}
}

static int	get_size(int num)
{
	int	move;

	move = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		move++;
	}
	return (move);
}

char	*ft_itoa(int num)
{
	int		len;
	char	*sol;

	len = get_size(num);
	sol = (char *)malloc((len + 1) * sizeof(char));
	if (!sol)
		exit_handler("itoa_error");
	sol[len] = '\0';
	put_num(sol, num, len);
	return (sol);
}
