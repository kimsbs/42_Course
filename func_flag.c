/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:55:43 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/04 17:35:19 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	case_dot(char *string, int *move, t_list *sub)
{
	int		cnt;
	int		tmp;

	tmp = *move;
	cnt = 0;
	if ((sub->precision = ft_atoi(&string[tmp + 1], &cnt)) >= 0)
	{
		sub->dot = 1;
		sub->zero = 0;
	}
	*move += cnt;
}

void	case_star(char *string, int *move, va_list op, t_list *sub)
{
	int		tmp;

	tmp = *move;
	if (string[tmp - 1] == '.')
	{
		if ((sub->precision = va_arg(op, int)) >= 0)
		{
			sub->dot = 1;
			sub->zero = 0;
		}
		else
			sub->dot = 0;
	}
	else
	{
		if (!sub->width)
		{
			sub->width = va_arg(op, int);
			if (sub->width < 0)
			{
				sub->width *= -1;
				sub->minus = 1;
			}
		}
	}
}

void	case_num(char *string, int *move, t_list *sub)
{
	int		cnt;
	int		tmp;

	tmp = *move;
	if (!sub->width)
	{
		cnt = 0;
		sub->width = ft_atoi(&string[tmp], &cnt);
		*move += cnt - 1;
	}
}
