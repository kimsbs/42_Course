/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:24:57 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 15:42:06 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLVE_H
# define SOLVE_H

void	swap(int *a, int *b);

void	rev_tmp(int *tmp, int size);

int		checking(int *tmp, int size);

int		check_main(int arr[][11], int size);

void	makezero(int arr[][11]);

#endif
