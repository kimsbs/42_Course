/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:28:03 by ksy               #+#    #+#             */
/*   Updated: 2021/12/23 21:30:59 by ksy              ###   ########.fr       */
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
	pthread_mutex_destroy(&data->die);
	free(data->mutex);
	free(data);
	free(philo);
}

void	lets_doing(char **argv)
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
	i = -1;
	while (++i < val.num_of_philo)
		pthread_create(&philo[i].thread, NULL, &get_fork, &philo[i]);
	i = -1;
	while (++i < val.num_of_philo)
		pthread_join(philo[i].thread, NULL);
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
	return (0);
}
