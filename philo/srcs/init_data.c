/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:24:57 by ksy               #+#    #+#             */
/*   Updated: 2021/12/29 10:25:29 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	val_init(char **argv, t_argc *val)
{
	val->num_of_philo = ft_atoi(argv[1]);
	val->time_to_die = ft_atoi(argv[2]);
	val->time_to_eat = ft_atoi(argv[3]);
	val->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		val->number_of_must_eat = ft_atoi(argv[5]);
	else
		val->number_of_must_eat = 1;
	if (val->num_of_philo < 1 || val->time_to_die < 0 \
		|| val->time_to_die < 0 || val->time_to_sleep < 0)
	{
		printf("wrong input!! ");
		return (0);
	}
	return (1);
}

int	data_cnt(t_argc *val, t_data *data)
{
	int	i;

	i = -1;
	data->cnt = (int *)malloc(sizeof(int) * val->num_of_philo);
	if (!data->cnt)
	{
		free(data->mutex);
		return (0);
	}
	while (++i < val->num_of_philo)
		data->cnt[i] = 0;
	return (1);
}

int	init_data(char **argv, t_argc *val, t_data *data)
{
	int	i;

	i = -1;
	if (!val_init(argv, val) || val->num_of_philo == 1)
	{
		if (val->num_of_philo == 1)
			printf("philosopher can not eat\n");
		free(data);
		return (0);
	}
	data->mutex = (pthread_mutex_t *)malloc(sizeof \
		(pthread_mutex_t) * val->num_of_philo);
	if (!data->mutex)
		return (0);
	data->info = val;
	if (!data_cnt(val, data))
		return (0);
	data->dead = 0;
	data->flag = 0;
	i = -1;
	while (++i < val->num_of_philo)
		pthread_mutex_init(&data->mutex[i], NULL);
	pthread_mutex_init(&data->print, NULL);
	return (1);
}

t_philo	*init_philo(char **argv, t_argc *val, t_data *data)
{
	int		i;
	t_philo	*philo;

	i = -1;
	if (!init_data(argv, val, data))
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo) * val->num_of_philo);
	if (!philo)
	{
		data_free(data);
		return (0);
	}
	gettimeofday(&(philo[0].start), NULL);
	philo[0].last = philo[0].start;
	while (++i < val->num_of_philo)
	{
		philo[i].left_fork = 0;
		philo[i].right_fork = 0;
		philo[i].index = i;
		philo[i].data = data;
		philo[i].start = philo[0].start;
		philo[i].last = philo[0].last;
	}
	return (philo);
}
