/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 18:50:33 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/22 14:56:07 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	cnt;
	int	tmp;

	cnt = -1;
	while (++cnt < size / 2)
	{
		tmp = *(tab + cnt);
		*(tab + cnt) = *(tab + size - cnt - 1);
		*(tab + size - cnt - 1) = tmp;
	}
}
