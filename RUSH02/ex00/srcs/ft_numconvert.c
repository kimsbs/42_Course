/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyolee <yong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 11:41:29 by jaeyolee          #+#    #+#             */
/*   Updated: 2021/03/14 18:33:13 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_100_num(unsigned int nbr)
{
	unsigned int	div;
	unsigned int	tmp;

	div = 100;
	while (nbr)
	{
		if (nbr >= div)
		{
			if (nbr < 20)
			{
				print_dic_value(itoa(nbr));
				break ;
			}
			tmp = nbr / div;
			if (nbr < 100)
				tmp *= 10;
			nbr = nbr % div;
			print_dic_value(itoa(tmp));
			if (div >= 10 && tmp < 10)
				print_dic_value(itoa(div));
		}
		else
			div /= 10;
	}
}

void	shirink_base(char **base, int size)
{
	char	*tmp;

	tmp = *base;
	while (*tmp)
		++tmp;
	tmp = tmp - size;
	*tmp = '\0';
}

void	get_upto_100_num(int size, char **str, int *len, char **base)
{
	int	tmp;

	shirink_base(base, size);
	if ((tmp = ft_atoi(*str, size)))
	{
		print_100_num(tmp);
		if (str_cmp(*base, "1"))
			print_dic_base(*base);
	}
	*str += size;
	*len -= size;
}

void	ft_putnbr(char *str)
{
	int		len;
	char	*base;
	int		i;

	if (!str_cmp(str, "0"))
	{
		print_dic_base("0");
		return ;
	}
	len = 0;
	while (str[len])
		++len;
	base = (char *)malloc(sizeof(char) * (len + 2));
	base[0] = '1';
	i = 1;
	while (i <= len)
		base[i++] = '0';
	base[len + 1] = '\0';
	get_upto_100_num(len % 3, &str, &len, &base);
	while (len)
		get_upto_100_num(3, &str, &len, &base);
	free(base);
}
