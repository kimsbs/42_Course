/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:18:18 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/07 15:31:13 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_string(char *print, t_list *sub, int print_width)
{
	char	set;
	int		tmp;

	tmp = sub->precision - ft_strlen(print);
	set = ' ';
	if (sub->zero == 1)
		set = '0';
	if (sub->minus)
	{
		set = ' ';
		if (sub->dot)
			ft_printnstr(print, &sub->precision);
		else
			ft_putstr(print);
	}
	while (print_width-- > 0)
		write(1, &set, 1);
	if (!sub->minus)
	{
		if (sub->dot)
			ft_printnstr(print, &sub->precision);
		else
			ft_putstr(print);
	}
}

int		print_function_string(char *print, int flag, t_list *sub)
{
	int len;
	int str_len;
	int	print_width;

	str_len = ft_strlen(print);
	if (sub->dot)
	{
		len = is_max(sub->width, is_min(sub->precision, str_len));
		print_width = len - is_min(sub->precision, str_len);
	}
	else
	{
		len = is_max(sub->width, str_len);
		print_width = len - str_len;
	}
	if (len <= 0 && sub->dot == 0)
		len = str_len;
	if (flag)
		print_string(print, sub, print_width);
	free(print);
	free(sub);
	return (len);
}
