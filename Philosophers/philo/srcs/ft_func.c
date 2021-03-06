/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:20:05 by ksy               #+#    #+#             */
/*   Updated: 2022/03/16 14:32:33 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	ft_atoi(char *s)
{
	int	tmp;
	int	sol;
	int	cur;
	int	move;

	move = ft_strlen(s);
	cur = 1;
	sol = 0;
	while (--move >= 0)
	{
		tmp = s[move] - '0';
		tmp *= cur;
		sol += tmp;
		cur *= 10;
	}
	return (sol);
}

long	ft_time(void)
{
	struct timeval	time;
	long			diff;

	gettimeofday(&time, NULL);
	diff = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (diff);
}

void	ft_usleep(long p_time)
{
	long	time;

	time = ft_time();
	while ((ft_time() - time) < p_time)
		usleep(p_time / 5);
}

void	ft_print_time(t_data *data, int index, const char *str)
{
	long long	timeval;

	pthread_mutex_lock(&data->print);
	timeval = data->cur - data->start;
	if (!data->dead)
		printf("%lldms %d philo %s\n", timeval, index, str);
	pthread_mutex_unlock(&data->print);
}
