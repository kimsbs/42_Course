/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:31:07 by ksy               #+#    #+#             */
/*   Updated: 2022/01/26 12:54:49 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	u_time(t_philo *philo, int flag)
{
	int				diff;
	struct timeval	time;

	if (flag)
		time = philo->start;
	else
		time = philo->last;
	gettimeofday(&(philo->end), NULL);
	diff = 0;
	diff += philo->end.tv_sec - time.tv_sec;
	diff *= 1000000;
	diff += philo->end.tv_usec - time.tv_usec;
	return (diff / 1000);
}

void	thinking(t_philo *philo, int index)
{
	int	timeval;

	timeval = u_time(philo, 0);
	if (!is_end(philo, timeval))
	{
		timeval = u_time(philo, 1);
		ft_print_time(philo, index, timeval, "thinking");
	}
}

void	sleeping(t_philo *philo, int index)
{
	int	timeval;

	timeval = u_time(philo, 0);
	if (!is_end(philo, timeval))
	{
		timeval = u_time(philo, 1);
		ft_print_time(philo, index, timeval, "sleeping");
		if (!philo->data->dead)
			ft_usleep(philo->data->info->time_to_sleep);
		thinking(philo, index);
	}
}

void	eating(t_philo *philo, int index)
{
	int	timeval;
	int	right_pos;

	right_pos = (index + 1) % philo->data->info->num_of_philo;
	timeval = u_time(philo, 0);
	if (!is_end(philo, 0))
	{
		timeval = u_time(philo, 1);
		ft_print_time(philo, index, timeval, "eating");
		if (!philo->data->dead)
		{
			ft_usleep(philo->data->info->time_to_eat);
			gettimeofday(&(philo->last), NULL);
		}
		philo->data->cnt[index] += 1;
		philo->left_fork = 0;
		philo->right_fork = 0;
		pthread_mutex_unlock(&philo->data->mutex[index]);
		pthread_mutex_unlock(&philo->data->mutex[right_pos]);
		sleeping(philo, index);
	}
}
