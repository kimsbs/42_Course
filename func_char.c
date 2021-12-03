/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 17:54:03 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/07 15:30:51 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char print, t_list *sub, int print_width, char set)
{
	if (sub->zero == 1)
		set = '0';
	if (sub->minus)
	{
		set = ' ';
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		write(1, &print, 1);
	}
	while (print_width-- > 0)
		write(1, &set, 1);
	if (!sub->minus)
	{
		while ((sub->precision)-- > 0)
			write(1, "0", 1);
		write(1, &print, 1);
	}
}

int		print_function_char(char print, int flag, t_list *sub)
{
	int len;
	int	print_width;

	len = 1;
	print_width = sub->width - is_max(sub->precision, len);
	sub->precision -= len;
	if (print_width > 0)
		len += print_width;
	if (sub->precision > 0)
		len += sub->precision;
	if (flag)
		print_char(print, sub, print_width, ' ');
	free(sub);
	return (len);
}
