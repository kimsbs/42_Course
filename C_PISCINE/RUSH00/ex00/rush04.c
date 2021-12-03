/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 10:59:19 by seungyki          #+#    #+#             */
/*   Updated: 2021/02/20 15:21:44 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(int x, char first, char middle, char last);

void	rush(int x, int y)
{
	int i;

	i = 0;
	while (i < y)
	{
		if (i == 0)
		{
			ft_putchar(x, 'A', 'B', 'C');
		}
		else if (i == y - 1)
		{
			ft_putchar(x, 'C', 'B', 'A');
		}
		else
		{
			ft_putchar(x, 'B', ' ', 'B');
		}
		i++;
	}
}