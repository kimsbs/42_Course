/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:24:11 by ksy               #+#    #+#             */
/*   Updated: 2022/02/11 01:18:48 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	right_fork(t_philo *philo, int index)
{
	int	timeval;
	int	right_pos;

	right_pos = (index + 1) % philo->data->info->num_of_philo;
	pthread_mutex_lock(&philo->data->fork[right_pos]);
	if (!is_end(philo->data))
	{
		philo->right_fork = 1;
		pthread_mutex_lock(&philo->data->time);
		gettimeofday(&philo->data->cur, NULL);
		timeval = diff_time(philo->data->start, philo->data->cur);
		ft_print_time(philo, index, timeval, "get right fork");
		pthread_mutex_unlock(&philo->data->time);
	}
	else
		pthread_mutex_unlock(&philo->data->fork[right_pos]);
	if (philo->left_fork == 0 && !philo->data->dead)
		left_fork(philo, philo->index);
}

void	left_fork(t_philo *philo, int index)
{
	int	timeval;

	pthread_mutex_lock(&philo->data->fork[index]);
	if (!is_end(philo->data))
	{
		philo->left_fork = 1;
		pthread_mutex_lock(&philo->data->time);
		gettimeofday(&philo->data->cur, NULL);
		timeval = diff_time(philo->data->start, philo->data->cur);
		ft_print_time(philo, index, timeval, "get left fork");
		pthread_mutex_unlock(&philo->data->time);
	}
	else
		pthread_mutex_unlock(&philo->data->fork[index]);
	if (philo->right_fork == 0 && !philo->data->dead)
		right_fork(philo, philo->index);
}

void	*get_fork(void *args)
{
	t_philo	*philo;
	int		max;

	philo = args;
	max = philo->data->info->number_of_must_eat;
	while (!philo->data->dead)
	{
		if (philo->data->cnt[philo->index] == max && philo->data->flag == 1)
			return (NULL);
		if (philo->index % 2)
			left_fork(philo, philo->index);
		else
		{
			if(philo->data->cnt[philo->index] == 0)
				ft_usleep(philo->data->info->time_to_eat / 2);
			right_fork(philo, philo->index);
		}
		if (philo->right_fork == 1 && philo->left_fork == 1)
			eating(philo, philo->index);
	}
	return (NULL);
}

void	threading(t_philo *philo, t_data *data, t_argc val)
{
	int			i;
	pthread_t	tmp;

	i = -1;
	while (++i < val.num_of_philo)
		pthread_create(&philo[i].thread, NULL, &get_fork, &philo[i]);
	pthread_create(&tmp, NULL, &dead_monitor, data);
	i = -1;
	while (++i < val.num_of_philo)
		pthread_join(philo[i].thread, NULL);
	pthread_join(tmp, NULL);
}

void	lets_doing(int argc, char **argv)
{
	t_argc	val;
	t_philo	*philo;
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return ;
	philo = init_philo(argv, &val, data);
	if (!philo)
		return ;
	if (argc == 6)
		data->flag = 1;
	if (philo->data->info->num_of_philo == 1)
	{
		free_all(philo, data);
		return ;
	}
	threading(philo, data, val);
	free_all(philo, data);
}
