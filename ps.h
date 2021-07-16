/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:23:07 by seungyki          #+#    #+#             */
/*   Updated: 2021/07/07 16:50:11 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	struct s_list	*prev;
	struct s_list	*next;
}t_list;

t_list	*make_node(int data);
t_list	*find_last(t_list *header);
void	print_list(t_list *a, t_list *b);
void	print_list_solo(t_list *list);
void	add_front(t_list **header, int data);
void	add_back(t_list **header, int data);
void	rm_front(t_list **header);
void	swap_element(t_list **header);
void	rotate(t_list **header);
void	rotate_a(t_list **a, int *cnt);
void	rotate_b(t_list **b, int *cnt);
void	rotate_rr(t_list **a, t_list **b, int *cnt);
void	reverse_rotate(t_list **header);
void	reverse_a(t_list **a, int *cnt);
void	reverse_b(t_list **b, int *cnt);
void	reverse_rr(t_list **a, t_list **b, int *cnt);
void	swap_a(t_list **a, int *cnt);
void	swap_b(t_list **b, int *cnt);
void	swap_s(t_list **a, t_list **b, int *cnt);
void	push_a(t_list **a, t_list **b, int *cnt);
void	push_b(t_list **a, t_list **b, int *cnt);
void	free_list(t_list **a, t_list **b);
void	a_to_b(t_list **a, t_list **b, int *cnt, int r);
void	b_to_a(t_list **a, t_list **b, int *cnt, int r);
int		ft_atoi(const char *str);
int		is_sorted(t_list **header);
#endif
