/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:47:39 by ksy               #+#    #+#             */
/*   Updated: 2021/12/23 21:49:42 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_all(t_philo *philo, t_data *data)
{
	sem_close(data->must_eat);
	sem_close(data->fork);
	sem_close(data->print);
	sem_close(data->die);
	free(data);
	free(philo);
}

void	lets_doing(char **argv)
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
	i = -1;
	while (++i < val.num_of_philo)
		pthread_create(&tid, NULL, &get_fork, &philo[i]);
	i = -1;
	while (++i < val.num_of_philo)
		pthread_join(tid, NULL);
	printf("%d\n", data->cnt);
	free_all(philo, data);
}

int	main(int argc, char **argv)
{
	if (!(argc == 6 || argc == 5))
	{
		argc_error();
		return (0);
	}
	lets_doing(argv);
}
