/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:24:57 by ksy               #+#    #+#             */
/*   Updated: 2022/03/16 14:22:24 by seungyki         ###   ########.fr       */
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
	if (val->num_of_philo <= 1 || val->time_to_die < 0 \
		|| val->time_to_eat < 0 || val->time_to_sleep < 0)
	{
		printf("wrong input!! ");
		return (0);
	}
	return (1);
}

int	init_data(char **argv, t_argc *val, t_data *data)
{
	int	i;

	i = -1;
	if (!val_init(argv, val) || val->num_of_philo == 1)
	{
		if (val->num_of_philo == 1)
			printf("One philosopher can not eat!!\n");
		return (0);
	}
	data->fork = (pthread_mutex_t *)malloc(sizeof \
		(pthread_mutex_t) * val->num_of_philo);
	if (!data->fork)
		return (0);
	data->info = val;
	data->dead = 0;
	data->flag = 0;
	i = -1;
	while (++i < val->num_of_philo)
		pthread_mutex_init(&data->fork[i], NULL);
	pthread_mutex_init(&data->print, NULL);
	return (1);
}

t_philo	*init_philo(char **argv, t_argc *val, t_data *data)
{
	int		i;
	t_philo	*philo;

	if (!init_data(argv, val, data))
		return (0);
	philo = (t_philo *)malloc(sizeof(t_philo) * val->num_of_philo);
	if (!philo)
	{
		data_free(data);
		return (0);
	}
	data->start = get_time(data);
	data->cur = data->start;
	i = -1;
	while (++i < val->num_of_philo)
	{
		philo[i].eat_cnt = 0;
		philo[i].left_fork = 0;
		philo[i].right_fork = 0;
		philo[i].index = i;
		philo[i].data = data;
		philo[i].last_meal = data->start;
	}
	data->philo = philo;
	return (philo);
}
