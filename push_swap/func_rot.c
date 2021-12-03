/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:14:41 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/06 14:19:46 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rotate(t_list **header)
{
	if (*header)
		*header = (*header)->next;
}

void	rotate_a(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rotate_rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
