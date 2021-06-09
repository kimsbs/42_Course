/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:39:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/09 15:04:22 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(va_list op, char *string, int last, int flag)
{
	int		move;
	t_list	*sub;

	sub = (t_list *)malloc(sizeof(t_list));
	if (!sub)
		return (-1);
	ft_memset(sub, 0, sizeof(t_list));
	move = -1;
	while (++move < last)
	{
		if (string[move] == '0')
			sub->zero = 1;
		else if (string[move] == '-')
			sub->minus = 1;
		else if (string[move] == '.')
			case_dot(string, &move, sub);
		else if (string[move] == '*')
			case_star(string, &move, op, sub);
		else if (string[move] >= '1' && string[move] <= '9')
			case_num(string, &move, sub);
	}
	return (write_something(string[last], op, flag, sub));
}

void	normmm(char c, int flag, int *return_value)
{
	if (flag)
		write(1, &c, 1);
	(*return_value)++;
}

int		available(va_list op, char *string, char *set, int flag)
{
	int		move;
	int		dummy;
	int		tmp;
	int		return_value;
	int		string_length;

	string_length = ft_strlen(string);
	move = -1;
	return_value = 0;
	while (++move < string_length)
		if (string[move] != '%')
			normmm(string[move], flag, &return_value);
		else
		{
			tmp = 1;
			while (move + tmp < string_length &&
					(is_in(set, string[move + tmp], flag) == -1))
				tmp++;
			if ((dummy = is_flag(op, &string[move], tmp, flag)) >= 0)
				return_value += dummy;
			else
				return (-1);
			move += tmp;
		}
	return (return_value);
}

int		ft_printf(const char *string, ...)
{
	va_list	op;
	int		return_value;
	char	*set;

	set = ft_strdup1("cspdiuxX%");
	if (!set)
		return (-1);
	va_start(op, string);
	return_value = available(op, (char *)string, set, 0);
	va_end(op);
	va_start(op, string);
	if (return_value != -1)
		available(op, (char *)string, set, 1);
	va_end(op);
	free(set);
	return (return_value);
}
