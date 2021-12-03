/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 00:20:35 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/18 06:15:19 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int tmp;
	int plus;
	int minus;

	i = 0;
	plus = 0;
	minus = 0;
	while (++i < length)
	{
		tmp = f(tab[i - 1], tab[i]);
		if (tmp > 0)
			minus = 1;
		else if (tmp < 0)
			plus = 1;
	}
	if (plus == 1 && minus == 1)
		return (0);
	return (1);
}
