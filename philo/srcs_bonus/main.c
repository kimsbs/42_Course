/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:47:39 by ksy               #+#    #+#             */
/*   Updated: 2021/12/28 18:22:35 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_philo *philo, t_data *data)
{
	sem_close(data->must_eat);
	sem_close(data->fork);
	sem_close(data->print);
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
			sem_wait(philo->data->must_eat);
			right_fork(philo, philo->index);
		}
		if (philo->right_fork == 1 && philo->left_fork == 1)
			eating(philo, philo->index);
	}
	return (NULL);
}

void	lets_doing(int argc, char **argv)
{
	t_argc		val;
	t_philo		*philo;
	t_data		*data;
	pthread_t	tid;
	int			i;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return ;
	philo = init_philo(argv, &val, data);
	if (!philo)
		return ;
	if (argc == 6)
		data->flag = 1;
	i = -1;
	while (++i < val.num_of_philo)
		pthread_create(&tid, NULL, &get_fork, &philo[i]);
	i = -1;
	while (++i < val.num_of_philo)
		pthread_join(tid, NULL);
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
}
