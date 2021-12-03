/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 10:04:41 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/17 10:43:07 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

void	ft_add(int a, int b, int sol);
void	ft_minus(int a, int b, int sol);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_product(int a, int b, int sol);
int		str_len(char *str);
int		str_cmp(char *a, char *b);
void	print_sol(int tmp);
void	ft_itoa(int tmp);
int		ft_atoi(char *str);
int		is_space(char c);

#endif
