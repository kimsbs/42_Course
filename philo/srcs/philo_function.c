/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:31:07 by ksy               #+#    #+#             */
/*   Updated: 2021/12/28 17:53:48 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	u_time(t_philo *philo, int flag)
{
	int				diff;
	struct timeval	time;

	diff = 0;
	gettimeofday(&(philo->end), NULL);
	if (flag)
		time = philo->start;
	else
		time = philo->last;
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
		pthread_mutex_lock(&philo->data->print);
		if (!philo->data->dead)
			printf("%dms %d philo thinking\n", timeval, index);
		pthread_mutex_unlock(&philo->data->print);
	}
}

void	sleeping(t_philo *philo, int index)
{
	int	sleep;
	int	timeval;

	timeval = u_time(philo, 0);
	if (!is_end(philo, timeval))
	{
		sleep = philo->data->info->time_to_sleep;
		timeval = u_time(philo, 1);
		pthread_mutex_lock(&philo->data->print);
		if (!philo->data->dead)
			printf("%dms %d philo sleeping\n", timeval, index);
		pthread_mutex_unlock(&philo->data->print);
		if (!philo->data->dead)
			ft_usleep(sleep);
		thinking(philo, index);
	}
}

void	eating(t_philo *philo, int index)
{
	int	eat;
	int	timeval;
	int	right_pos;

	right_pos = (index + 1) % philo->data->info->num_of_philo;
	timeval = u_time(philo, 0);
	if (!is_end(philo, 0))
	{
		philo->last = philo->end;
		timeval = u_time(philo, 1);
		pthread_mutex_lock(&philo->data->print);
		if (!philo->data->dead)
			printf("%dms %d philo eating\n", timeval, index);
		pthread_mutex_unlock(&philo->data->print);
		eat = philo->data->info->time_to_eat;
		if (!philo->data->dead)
			ft_usleep(eat);
		philo->data->cnt[index] += 1;
		philo->left_fork = 0;
		philo->right_fork = 0;
		pthread_mutex_unlock(&philo->data->mutex[index]);
		pthread_mutex_unlock(&philo->data->mutex[right_pos]);
		sleeping(philo, index);
	}
}
