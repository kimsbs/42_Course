#include "philo.h"

void	put_down_all_fork(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->info->num_of_philo)
		pthread_mutex_unlock(&philo->data->fork[i]);
}

void	all_the_philo_eat(t_philo *philo)
{
	int	i;

	if (!philo->data->flag)
		return ;
	i = -1;
	while (++i < philo->data->info->num_of_philo)
	{
		if (philo->data->cnt[i] < philo->data->info->number_of_must_eat)
			return ;
	}
	pthread_mutex_lock(&philo->data->print);
	printf("=====all the philo have eaten===\n");
	philo->data->dead = 1;
	pthread_mutex_unlock(&philo->data->print);
}

int	any_philo_dead(t_philo *philo)
{
	t_data *data;
	int	i;

	data = philo->data;
	gettimeofday(&data->cur, NULL);
	i = -1;
	while(++i < data->info->num_of_philo)
	{
		if(diff_time(data->philo[i].last_meal, data->cur) > data->info->time_to_die)
			return (i);
	}
	return (-1);
}

int	is_end(t_philo *philo)
{
	int	flag;
	int	deadman;

	flag = 0;
	pthread_mutex_lock(&philo->data->print);
	if (philo->data->dead)
		flag = 1;
	deadman = any_philo_dead(philo);
    if (deadman != -1 && !flag)
	{
        printf("====%dms %d philo dead====\n", diff_time(philo->data->start, philo->data->cur), deadman);
		philo->data->dead = 1;
        put_down_all_fork(philo);
		flag = 1;
	}
	pthread_mutex_unlock(&philo->data->print);
	return (flag);
}