/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:24:11 by ksy               #+#    #+#             */
/*   Updated: 2022/03/16 14:56:50 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	ft_print_time(philo->data, index, "sleeping");
	ft_usleep(philo->data->info->time_to_sleep);
	ft_print_time(philo->data, index, "thinking");
}

void	right_fork(t_philo *philo, int index)
{
	int	right_pos;

	right_pos = (index + 1) % philo->data->info->num_of_philo;
	pthread_mutex_lock(&philo->data->fork[right_pos]);
	if (!philo->data->dead)
	{
		philo->right_fork = 1;
		ft_print_time(philo->data, index, "get right fork");
	}
	else
		pthread_mutex_unlock(&philo->data->fork[right_pos]);
	if (philo->left_fork == 0 && !philo->data->dead)
		left_fork(philo, philo->index);
}

void	left_fork(t_philo *philo, int index)
{
	pthread_mutex_lock(&philo->data->fork[index]);
	if (!philo->data->dead)
	{
		philo->left_fork = 1;
		ft_print_time(philo->data, index, "get left fork");
	}
	else
		pthread_mutex_unlock(&philo->data->fork[index]);
	if (philo->right_fork == 0 && !philo->data->dead)
		right_fork(philo, philo->index);
}

void	*get_fork(void *args)
{
	t_philo	*philo;
	t_data	*data;
	int		max;

	philo = args;
	data = philo->data;
	max = philo->data->info->number_of_must_eat;
	while (!data->dead)
	{
		if (philo->data->flag && philo->eat_cnt \
			>= philo->data->info->number_of_must_eat)
			return (NULL);
		if (philo->index % 2 == 1)
			left_fork(philo, philo->index);
		else
		{
			if (philo->eat_cnt == 0)
				ft_usleep(philo->data->info->time_to_eat / 2);
			right_fork(philo, philo->index);
		}
		if (philo->right_fork == 1 && philo->left_fork == 1)
			eating(philo, philo->index);
	}
	return (NULL);
}

void	threading(t_philo *philo, t_argc val)
{
	int			i;

	i = -1;
	while (++i < val.num_of_philo)
		pthread_create(&philo[i].thread, NULL, &get_fork, &philo[i]);
	dead_monitor(philo->data);
	i = -1;
	while (++i < val.num_of_philo)
		pthread_detach(philo[i].thread);
}
