#include "philo.h"

void	put_down_all_fork(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->info->num_of_philo)
		pthread_mutex_unlock(&data->fork[i]);
}

void	all_the_philo_eat(t_data *data)
{
	int	i;

	if (!data->flag)
		return ;
	i = -1;
	while (++i < data->info->num_of_philo)
	{
		if (data->cnt[i] < data->info->number_of_must_eat)
			return ;
	}
	pthread_mutex_lock(&data->print);
	if (!data->dead)
	{
		printf("=====all the philo have eaten===\n");
		data->dead = 1;
	}
	pthread_mutex_unlock(&data->print);
}

void	is_end(t_data *data)
{
	int	diff;
	int	deadman;
	int	die;
	int	i;

	deadman = -1;
	die = data->info->time_to_die;
	i = -1;
	while (++i < data->info->num_of_philo)
	{
		diff = diff_time(data->philo[i].last_meal, data->cur);
		if (diff > die)
			deadman = i;
	}
	if (deadman != -1)
	{
		diff = diff_time(data->start, data->cur);
		pthread_mutex_lock(&data->print);
		data->dead = 1;
		printf("====%dms %d philo dead====\n", diff, deadman);
		pthread_mutex_unlock(&data->print);
		put_down_all_fork(data);
	}
}

void	*dead_monitor(void *args)
{
	t_data	*data;
	int		diff;

	data = args;
	while (!data->dead)
	{
		gettimeofday(&data->cur, NULL);
		diff = diff_time(data->tmp, data->cur);
		if (diff >= 3)
		{
			data->tmp = data->cur;
			is_end(data);
			all_the_philo_eat(data);
		}
	}
	return (NULL);
}

int	any_dead(t_data *data)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(&data->print);
	if (data->dead)
		flag = 1;
	pthread_mutex_unlock(&data->print);
	gettimeofday(&data->cur, NULL);
	return (flag);
}
