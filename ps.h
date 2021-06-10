/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:23:07 by seungyki          #+#    #+#             */
/*   Updated: 2021/06/10 21:20:03 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				index;
	struct	s_list	*prev;
	struct	s_list	*next;
}					t_list;

t_list	*make_node(int data);
t_list	*find_last(t_list *header);
void	print_list(t_list *header);
void	add_front(t_list **header, int data);
void	rm_front(t_list **header);
void	swap_element(t_list **header);
void	rotate(t_list **header);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_rr(t_list **a, t_list **b);
void	reverse_rotate(t_list **header);
void	reverse_a(t_list **a);
void	reverse_b(t_list **b);
void	reverse_rr(t_list **a, t_list **b);
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_s(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);

#endif
