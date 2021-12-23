/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:44:26 by ksy               #+#    #+#             */
/*   Updated: 2021/12/23 21:56:15 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	put_down_all_fork(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->info->num_of_philo + 1)
		sem_post(philo->data->fork);
	sem_post(philo->data->print);
}

int	is_end(t_philo *philo, int timeval)
{
	if (philo->data->cnt == philo->data->info->number_of_must_eat)
	{
		put_down_all_fork(philo);
		philo->data->dead = 1;
		return (1);
	}
	else if (philo->data->dead)
		return (1);
	else if (timeval > philo->data->info->time_to_die)
	{
		philo->data->dead = 1;
		sem_wait(philo->data->die);
		printf("=====%dms %d philo is died====\n", timeval / 1000, philo->index);
		put_down_all_fork(philo);
		sem_post(philo->data->die);
		return (1);
	}
	return (0);
}

void	right_fork(t_philo *philo, int index)
{
	int	timeval;

	sem_wait(philo->data->fork);
	sem_wait(philo->data->print);
	timeval = u_time(philo, 0);
	if (!is_end(philo, timeval))
	{
		philo->right_fork = 1;
		timeval = u_time(philo, 1);
		printf("%dms %d philo get right fork\n", timeval, index);
	}
	else
		sem_post(philo->data->fork);
	sem_post(philo->data->print);
}

void	left_fork(t_philo *philo, int index)
{
	int	timeval;

	timeval = u_time(philo, 0);
	sem_wait(philo->data->fork);
	sem_wait(philo->data->print);
	if (!is_end(philo, timeval))
	{
		philo->left_fork = 1;
		timeval = u_time(philo, 1);
		printf("%dms %d philo get left fork\n", timeval, index);
	}
	else
		sem_post(philo->data->fork);
	sem_post(philo->data->print);
}

void	*get_fork(void *args)
{
	t_philo	*philo;
	int		index;

	philo = args;
	index = philo->index;
	if (index)
	{
		left_fork(philo, index);
		if (philo->left_fork == 1)
			right_fork(philo, index);
	}
	else
	{
		sem_wait(philo->data->must_eat);
		right_fork(philo, index);
		if (philo->right_fork == 1)
			left_fork(philo, index);
	}
	if (philo->right_fork == 1 && philo->left_fork == 1)
		eating(philo, index);
	return (NULL);
}
