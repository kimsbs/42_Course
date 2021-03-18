/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 12:31:39 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/25 12:37:36 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int sol;

	if (power < 0)
		return (0);
	sol = 1;
	while (power--)
	{
		sol *= nb;
	}
	return (sol);
}
