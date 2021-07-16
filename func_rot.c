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

void	rotate_a(t_list **a, int *cnt)
{
	rotate(a);
	*cnt += 1;
	write(1, "ra\n", 3);
}

void	rotate_b(t_list **b, int *cnt)
{
	rotate(b);
	*cnt += 1;
	write(1, "rb\n", 3);
}

void	rotate_rr(t_list **a, t_list **b, int *cnt)
{
	rotate(a);
	rotate(b);
	*cnt += 1;
	write(1, "rr\n", 3);
}
