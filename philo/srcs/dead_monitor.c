/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:31:07 by ksy               #+#    #+#             */
/*   Updated: 2022/03/14 21:37:30 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_all_fork(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->info->num_of_philo)
		pthread_mutex_unlock(&data->fork[i]);
}

void	mutexing(t_data *data, int flag)
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
	free_all(data);
}

void	*dead_monitor(t_data *data)
{
	int		i;
	int		eat_cnt;

	while (!data->dead)
	{
		eat_cnt = 0;
		i = -1;
		while (++i < data->info->num_of_philo)
		{
			data->cur = get_time(data);
			if (data->cur - data->philo[i].last_meal > data->info->time_to_die \
				&& data->philo[i].eat_cnt < data->info->number_of_must_eat)
				mutexing(data, i);
			if (data->philo[i].eat_cnt >= data->info->number_of_must_eat)
				eat_cnt++;
		}
		if (!data->dead && data->flag \
			&& eat_cnt == data->info->num_of_philo)
			mutexing(data, -1);
	}
	return (NULL);
}

int	any_dead(t_data *data)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&data->print);
	if (data->dead)
		flag = 1;
	pthread_mutex_unlock(&data->print);
	return (flag);
}
