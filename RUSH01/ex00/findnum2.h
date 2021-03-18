/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findnum2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:59:39 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 21:40:05 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FINDNUM2_H
# define FINDNUM2_H

void	inputmetrix(int arr[][11], int i, int j, int size);

int		row_count(int arr[][11], int size);

int		col_count(int arr[][11], int size);

int		rowpossible(int arr[][11], int q, int data, int size);

int		colpossible(int arr[][11], int p, int data, int size);

#endif
