/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:31:07 by ksy               #+#    #+#             */
/*   Updated: 2022/03/14 21:20:41 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(t_data *data)
{
	gettimeofday(&data->val, NULL);
	return ((data->val.tv_sec * 1000) + (data->val.tv_usec / 1000));
}

void	sleep_and_think(t_philo *philo, int index)
{
	ft_print_time(philo->data, index, "sleeping");
	if (!philo->data->dead)
	{
		ft_usleep(philo->data->info->time_to_sleep);
		ft_print_time(philo->data, index, "thinking");
	}
}

void	eating(t_philo *philo, int index)
{
	int	right_pos;

	right_pos = (index + 1) % philo->data->info->num_of_philo;
	ft_print_time(philo->data, index, "eating");
	ft_usleep(philo->data->info->time_to_eat);
	philo->last_meal = get_time(philo->data);
	philo->eat_cnt += 1;
	philo->left_fork = 0;
	philo->right_fork = 0;
	pthread_mutex_unlock(&philo->data->fork[index]);
	pthread_mutex_unlock(&philo->data->fork[right_pos]);
	sleep_and_think(philo, philo->index);
}
