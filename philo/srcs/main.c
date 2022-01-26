/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:28:03 by ksy               #+#    #+#             */
/*   Updated: 2022/01/26 13:07:21 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_philo *philo, t_data *data)
{
	int	max;
	int	i;

	i = -1;
	max = philo->data->info->num_of_philo;
	while (++i < max)
		pthread_mutex_destroy(&data->mutex[i]);
	pthread_mutex_destroy(&data->print);
	free(data->mutex);
	free(data->cnt);
	free(data);
	free(philo);
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
			ft_usleep(10);
			right_fork(philo, philo->index);
		}
		if (philo->right_fork == 1 && philo->left_fork == 1)
			eating(philo, philo->index);
	}
	return (NULL);
}

void	lets_doing(int argc, char **argv)
{
	t_argc	val;
	t_philo	*philo;
	t_data	*data;
	int		i;

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
	i = -1;
	while (++i < val.num_of_philo)
		pthread_create(&philo[i].thread, NULL, &get_fork, &philo[i]);
	i = -1;
	while (++i < val.num_of_philo)
		pthread_join(philo[i].thread, NULL);
	free_all(philo, data);
}

int	main(int argc, char **argv)
{
	if (!(argc == 6 || argc == 5))
	{
		argc_error();
		return (0);
	}
	lets_doing(argc, argv);
	return (0);
}
