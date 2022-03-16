/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:28:03 by ksy               #+#    #+#             */
/*   Updated: 2022/03/16 14:58:26 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_data *data)
{
	int	max;
	int	i;

	i = -1;
	max = data->info->num_of_philo;
	while (++i < max)
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->print);
	free(data->fork);
	free(data->philo);
}

int	main(int argc, char **argv)
{
	t_argc	val;
	t_philo	*philo;
	t_data	data;

	if (!(argc == 6 || argc == 5))
	{
		argc_error();
		return (0);
	}
	philo = init_philo(argv, &val, &data);
	if (!philo)
		return (0);
	if (argc == 6)
		data.flag = 1;
	threading(philo, val);
	free_all(&data);
	return (0);
}
