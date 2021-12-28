/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:24:11 by ksy               #+#    #+#             */
/*   Updated: 2021/12/28 17:42:41 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_all_fork(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->info->num_of_philo)
		pthread_mutex_unlock(&philo->data->mutex[i]);
}

int	all_the_philo_eat(t_philo *philo)
{
	int	i;

	if (!philo->data->flag)
		return (0);
	i = -1;
	while (++i < philo->data->info->num_of_philo)
	{
		if (philo->data->cnt[i] < philo->data->info->number_of_must_eat)
			return (0);
	}
	return (1);
}

int	is_end(t_philo *philo, int timeval)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->dead)
		flag = 1;
	if (all_the_philo_eat(philo) && !flag)
	{
		put_down_all_fork(philo);
		philo->data->dead = 1;
		printf("=====all the philo have eaten===\n");
		flag = 1;
	}
	if (timeval > philo->data->info->time_to_die && !flag)
	{
		philo->data->dead = 1;
		timeval = u_time(philo, 1);
		printf("=====%dms %d philo is died====\n", timeval, philo->index);
		put_down_all_fork(philo);
		flag = 1;
	}
	pthread_mutex_unlock(&philo->data->print);
	return (flag);
}

void	right_fork(t_philo *philo, int index)
{
	int	timeval;
	int	right_pos;

	right_pos = (index + 1) % philo->data->info->num_of_philo;
	pthread_mutex_lock(&philo->data->mutex[right_pos]);
	timeval = u_time(philo, 0);
	if (!is_end(philo, timeval))
	{
		philo->right_fork = 1;
		timeval = u_time(philo, 1);
		pthread_mutex_lock(&philo->data->print);
		if (!philo->data->dead)
			printf("%dms %d philo get right fork\n", timeval, index);
		pthread_mutex_unlock(&philo->data->print);
	}
	else
		pthread_mutex_unlock(&philo->data->mutex[right_pos]);
	if (philo->left_fork == 0 && !philo->data->dead)
		left_fork(philo, philo->index);
}

void	left_fork(t_philo *philo, int index)
{
	int	timeval;

	pthread_mutex_lock(&philo->data->mutex[index]);
	timeval = u_time(philo, 0);
	if (!is_end(philo, timeval))
	{
		philo->left_fork = 1;
		timeval = u_time(philo, 1);
		pthread_mutex_lock(&philo->data->print);
		if (!philo->data->dead)
			printf("%dms %d philo get left fork\n", timeval, index);
		pthread_mutex_unlock(&philo->data->print);
	}
	else
		pthread_mutex_unlock(&philo->data->mutex[index]);
	if (philo->right_fork == 0 && !philo->data->dead)
		right_fork(philo, philo->index);
}
