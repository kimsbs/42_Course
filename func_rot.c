/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:14:41 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:19:21 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	rotate(t_list **header)
{
	*header = (*header)->next;
}

void	rotate_a(t_list **a)
{
	rotate(a);
}

void	rotate_b(t_list **b)
{
	rotate(b);
}

void	rotate_rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
