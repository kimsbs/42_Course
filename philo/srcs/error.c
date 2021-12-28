/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:22:30 by ksy               #+#    #+#             */
/*   Updated: 2021/12/27 19:50:39 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	argc_error(void)
{
	printf("input 4 or 5 arguments\n");
	printf("1: [number_of_philosophers]\n2: [time_to_die]\n");
	printf("3: [time_to_eat]\n4: [time_to_sleep]\n");
	printf("5: [number_of_times_each_philosopher_must_eat : optional]\n");
}

int	data_free(t_data *data)
{
	int	max;
	int	i;

	i = -1;
	max = data->info->num_of_philo;
	while (++i < max)
		pthread_mutex_destroy(&data->mutex[i]);
	pthread_mutex_destroy(&data->print);
	free(data->cnt);
	free(data->mutex);
	free(data);
	return (0);
}
