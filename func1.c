/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:39:09 by seungyki          #+#    #+#             */
/*   Updated: 2021/05/18 14:50:54 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t move;

	move = 0;
	while (s[move])
		move++;
	return (move);
}

static	void	ft_putnbr_recursive(int n)
{
	int		tmp;
	char	c;

	if (n >= 10 || n <= -10)
		ft_putnbr_recursive(n / 10);
	tmp = n % 10;
	if (tmp < 0)
		tmp *= -1;
	c = tmp + '0';
	write(1, &c, sizeof(c));
}

void			ft_putnbr(int n)
{
	if (n == 0)
		write(1, "0", sizeof(char));
	else if (n < 0)
	{
		write(1, "-", sizeof(char));
		ft_putnbr_recursive(n);
	}
	else
		ft_putnbr_recursive(n);
}

void		ft_putstr(char *s)
{
	while(*s)
	{
		write(1, s, sizeof(char));
		s++;
	}
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	int		move;
	char	*dup;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (0);
	move = 0;
	while (s1[move])
	{
		dup[move] = s1[move];
		move++;
	}
	dup[move] = '\0';
	return (dup);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			move;
	unsigned char	tmp;
	unsigned char	*src;

	src = (unsigned char *)b;
	tmp = (unsigned char)c;
	move = 0;
	while (move < len)
	{
		src[move] = tmp;
		move++;
	}
	return (b);
}

int				ft_atoi(const char *str, int *cnt)
{
	long	sol;
	char	*tmp;

	tmp = (char *)str;
	sol = 0;
	while (*tmp >= '0' && *tmp <= '9')
	{
		sol = (sol * 10) + (*tmp - '0');
		tmp++;
		if (sol > 2147483647)
			return (-1);
		if (sol < -2147483648)
			return (-1);
		(*cnt)++;
	}
	return ((int)sol);
}

int			is_max(int a, int b)
{
	if(a>b)
		return (a);
	return(b);
}

static	int		find_size(int n)
{
	int		size;

	size = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static	void	input_data(int n, char *sol, int size, int start)
{
	int		tmp;

	while (size >= start)
	{
		tmp = n % 10;
		if (tmp < 0)
			tmp *= -1;
		n /= 10;
		sol[size] = tmp + '0';
		size--;
	}
}

char			*ft_itoa(int n)
{
	char	*sol;
	int		size;
	int		start;

	size = find_size(n);
	if (n < 0)
		size++;
	if (!(sol = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
	{
		start = 1;
		sol[0] = '-';
	}
	else
		start = 0;
	input_data(n, sol, size - 1, start);
	sol[size] = '\0';
	return (sol);
}

char *make_str(char c)
{
	char *tmp;

	tmp = (char *)malloc(sizeof(char) * 2);
	tmp[0] = c;
	tmp[1] = '\0';
	return (tmp);
}
