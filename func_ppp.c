/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ppp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:15:53 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 16:53:34 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ppp2(char *print, t_list *sub, int print_width, char set)
{
	if (print[0] == '-' && set == '0')
		write(1, &*(print++), 1);
	while (print_width-- > 0)
		write(1, &set, 1);
	if (!sub->minus)
	{
		write(1, "0x", 2);
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		ft_putstr(print);
	}
}

void	print_ppp(char *print, t_list *sub, int print_width)
{
	char set;

	set = ' ';
	if (sub->zero == 1)
		set = '0';
	if (!ft_strcmp(print, "0") && sub->dot && sub->precision < 2)
	{
		print_width++;
		print[0] = '\0';
	}
	if (sub->minus)
	{
		set = ' ';
		write(1, "0x", 2);
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		ft_putstr(print);
	}
	print_ppp2(print, sub, print_width, set);
}

int		print_function_ppp(char *print, int flag, t_list *sub)
{
	int len;
	int	print_width;
	int tmp;

	len = ft_strlen(print);
	tmp = len + 2;
	print_width = sub->width - is_max(sub->precision, tmp);
	sub->precision -= len;
	if (sub->precision > 2)
		len += sub->precision;
	if (print_width > 0)
		len += print_width;
	if (!ft_strcmp(print, "0") && sub->dot && sub->precision < 0
			&& print_width < 0)
		len--;
	if (flag)
		print_ppp(print, sub, print_width);
	free(sub);
	free(print);
	return (len + 2);
}
