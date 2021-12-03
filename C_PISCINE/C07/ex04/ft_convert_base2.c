/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 13:28:23 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/10 20:36:25 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		find_base(char c, char *base);

int		possible(char c, char *base);

int		base_check(char *base);

void	itoa(int sol, char *base_to, int size, char *str)
{
	int quotient;
	int remain;
	int b_len;
	int cnt;

	if (sol < 0)
		str[0] = '-';
	b_len = 0;
	while (base_to[b_len])
		b_len++;
	cnt = 0;
	quotient = sol;
	if (sol == 0)
		str[0] = base_to[0];
	while (quotient)
	{
		remain = quotient % b_len;
		if (remain < 0)
			remain *= -1;
		str[size - cnt] = base_to[remain];
		quotient /= b_len;
		cnt++;
	}
}

char	*ft_convert_base2(int sol, char *base_to)
{
	int		b_len;
	int		tmp;
	int		size;
	char	*str;

	b_len = 0;
	while (base_to[b_len])
		b_len++;
	if (b_len <= 1)
		return (0);
	tmp = sol;
	size = 0;
	while (tmp)
	{
		size++;
		tmp /= b_len;
	}
	if (sol <= 0)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	itoa(sol, base_to, size - 1, str);
	return (str);
}

int		space_first(char *nbr, char *base_from)
{
	int		check;

	check = 0;
	while (*nbr)
	{
		if (find_base(*nbr, base_from) != -1)
			break ;
		else if (possible(*nbr, base_from) && check == 0)
		{
			if (possible(*nbr, base_from) <= 2)
				check = 1;
		}
		else if (possible(*nbr, base_from) == 3 && check == 1)
			return (0);
		nbr++;
	}
	return (1);
}
