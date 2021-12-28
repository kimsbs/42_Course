/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:44:26 by ksy               #+#    #+#             */
/*   Updated: 2021/12/28 18:20:50 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	put_down_all_fork(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->info->num_of_philo + 1)
		sem_post(philo->data->fork);
	i = -1;
	while (++i < philo->data->info->num_of_philo + 1)
		sem_post(philo->data->must_eat);
	i = -1;
	while (++i < philo->data->info->num_of_philo + 1)
		sem_post(philo->data->print);
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
	int	rt;

	rt = 0;
	sem_wait(philo->data->print);
	if (philo->data->dead)
		rt = 1;
	if (all_the_philo_eat(philo) && rt == 0)
	{
		philo->data->dead = 1;
		timeval = u_time(philo, 1);
		printf("=====%dms all the philo have eaten====\n", timeval);
		rt = 2;
	}
	if (timeval > philo->data->info->time_to_die && rt == 0)
	{
		philo->data->dead = 1;
		timeval = u_time(philo, 1);
		printf("=====%dms %d philo is died====\n", timeval, philo->index);
		rt = 2;
	}
	sem_post(philo->data->print);
	if (rt > 1)
		put_down_all_fork(philo);
	return (rt);
}

void	right_fork(t_philo *philo, int index)
{
	int	timeval;

	sem_wait(philo->data->fork);
	timeval = u_time(philo, 0);
	if (!is_end(philo, timeval))
	{
		philo->right_fork = 1;
		timeval = u_time(philo, 1);
		sem_wait(philo->data->print);
		if (!philo->data->dead)
			printf("%dms %d philo get right fork\n", timeval, index);
		sem_post(philo->data->print);
	}
	else
		sem_post(philo->data->fork);
	if (philo->left_fork == 0 && !philo->data->dead)
		left_fork(philo, philo->index);
}

void	left_fork(t_philo *philo, int index)
{
	int	timeval;

	timeval = u_time(philo, 0);
	sem_wait(philo->data->fork);
	if (!is_end(philo, timeval))
	{
		philo->left_fork = 1;
		timeval = u_time(philo, 1);
		sem_wait(philo->data->print);
		if (!philo->data->dead)
			printf("%dms %d philo get left fork\n", timeval, index);
		sem_post(philo->data->print);
	}
	else
		sem_post(philo->data->fork);
	if (philo->right_fork == 0 && !philo->data->dead)
		right_fork(philo, philo->index);
}
