/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:31:07 by ksy               #+#    #+#             */
/*   Updated: 2022/03/16 14:58:35 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(t_data *data)
{
	gettimeofday(&data->val, NULL);
	return ((data->val.tv_sec * 1000) + (data->val.tv_usec / 1000));
}

void	*mutexing(t_data *data, int flag)
{
	long long	time;

	pthread_mutex_lock(&data->print);
	if (flag != -1 && !data->dead)
	{
		time = data->cur - data->start;
		printf("===%lldms %d philo %s===\n", time, flag, "dead");
	}
	data->dead = 1;
	if (flag == -1)
		printf("===Eat finish!!!===\n");
	pthread_mutex_unlock(&data->print);
	return (0);
}

void	*dead_monitor(t_data *data)
{
	int		i;
	int		eat_cnt;

	while (!data->dead)
	{
		eat_cnt = 0;
		i = -1;
		while (!data->dead && ++i < data->info->num_of_philo)
		{
			data->cur = get_time(data);
			if (data->cur - data->philo[i].last_meal > data->info->time_to_die \
				&& data->philo[i].eat_cnt < data->info->number_of_must_eat)
				return (mutexing(data, i));
			if (data->philo[i].eat_cnt >= data->info->number_of_must_eat)
				eat_cnt++;
		}
		if (!data->dead && data->flag \
			&& eat_cnt == data->info->num_of_philo)
			return (mutexing(data, -1));
	}
	return (NULL);
}
