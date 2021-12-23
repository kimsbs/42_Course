/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:43:16 by ksy               #+#    #+#             */
/*   Updated: 2021/12/23 21:43:35 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	argc_error(void)
{
	printf("input 4 or 5 arguments\n");
	printf("1: [number_of_philosophers]\n2: [time_to_die]\n");
	printf("3: [time_to_eat]\n4: [time_to_sleep]\n");
	printf("5: [number_of_times_each_philosopher_must_eat : optional]\n");
}
