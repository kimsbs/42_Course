/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 21:16:14 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:17:44 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	reverse_rotate(t_list **header)
{
	*header = (*header)->prev;
}

void	reverse_a(t_list **a)
{
	reverse_rotate(a);
}

void	reverse_b(t_list **b)
{
	reverse_rotate(b);
}

void	reverse_rr(t_list **a, t_list **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
