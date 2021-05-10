/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 13:47:25 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/10 17:54:56 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_putnbr_recursive(int n, int fd)
{
	int		tmp;
	char	c;

	if (n >= 10 || n <= -10)
		ft_putnbr_recursive(n / 10, fd);
	tmp = n % 10;
	if (tmp < 0)
		tmp *= -1;
	c = tmp + '0';
	write(fd, &c, sizeof(c));
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", sizeof(char));
	else if (n < 0)
	{
		write(fd, "-", sizeof(char));
		ft_putnbr_recursive(n, fd);
	}
	else
		ft_putnbr_recursive(n, fd);
}
