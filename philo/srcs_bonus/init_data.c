/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:45:30 by ksy               #+#    #+#             */
/*   Updated: 2021/12/28 18:31:26 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

sem_t	*ft_sem_open(char *name, int value)
{
	sem_unlink(name);
	return (sem_open(name, O_CREAT | O_EXCL, 0644, value));
}

void	val_init(char **argv, t_argc *val)
{
	val->num_of_philo = ft_atoi(argv[1]);
	val->time_to_die = ft_atoi(argv[2]);
	val->time_to_eat = ft_atoi(argv[3]);
	val->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		val->number_of_must_eat = ft_atoi(argv[5]);
	else
		val->number_of_must_eat = val->num_of_philo;
}

int	init_data(char **argv, t_argc *val, t_data *data)
{
	int	i;

	val_init(argv, val);
	if (val->num_of_philo == 1)
	{
		printf("philosopher can not eat\n");
		free(data);
		return (0);
	}
	data->info = val;
	data->cnt = (int *)malloc(sizeof(int) * val->num_of_philo);
	if (!data->cnt)
		return (0);
	i = -1;
	while (++i < val->num_of_philo)
		data->cnt[i] = 0;
	data->flag = 0;
	data->dead = 0;
	data->fork = ft_sem_open("fork", val->num_of_philo + 1);
	data->print = ft_sem_open("print", 1);
	data->must_eat = ft_sem_open("must_eat", 0);
	return (1);
}

void	del_data(t_data *data)
{
	free(data->cnt);
	sem_close(data->must_eat);
	sem_close(data->fork);
	sem_close(data->print);
	free(data);
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
		del_data(data);
		return (0);
	}
	gettimeofday(&(philo[0].start), NULL);
	philo[0].last = philo[0].start;
	i = -1;
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
