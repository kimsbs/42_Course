/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungyki <seungyki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 11:24:26 by seungyki          #+#    #+#             */
/*   Updated: 2021/03/07 15:41:39 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAME_H
# define FRAME_H

int		checker(int arr[][11], int size);

int		find_size(char *str);

void	make_input(char *str, int *arr);

void	make_metrix(int arr[][11], int *input, int size);

#endif
