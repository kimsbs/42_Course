/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:28:03 by ksy               #+#    #+#             */
/*   Updated: 2022/02/10 20:12:25 by ksy              ###   ########.fr       */
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
		pthread_mutex_destroy(&data->fork[i]);
	pthread_mutex_destroy(&data->print);
	free(data->fork);
	free(data->cnt);
	free(data);
	free(philo);
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
