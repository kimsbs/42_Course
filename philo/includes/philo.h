/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:39:06 by ksy               #+#    #+#             */
/*   Updated: 2022/03/16 14:49:12 by seungyki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_argc
{
	int	num_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_must_eat;
}	t_argc;

typedef struct s_data
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	int				dead;
	int				flag;
	t_argc			*info;
	long long		start;
	long long		cur;
	struct timeval	val;
	struct s_philo	*philo;
}	t_data;

typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	int				index;
	int				eat_cnt;
	long long		last_meal;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

int			ft_strlen(char *s);
int			ft_atoi(char *s);
void		argc_error(void);
t_philo		*init_philo(char **argv, t_argc *val, t_data *data);
void		*get_fork(void *args);
void		lets_doing(int argc, char **argv);
void		eating(t_philo *philo, int index);
void		sleep_and_think(t_philo *philo, int index);
int			diff_time(struct timeval before, struct timeval after);
int			data_free(t_data *data);
int			any_dead(t_data *data);
void		is_end(t_data *data);
void		left_fork(t_philo *philo, int index);
void		right_fork(t_philo *philo, int index);
void		ft_print_time(t_data *data, int index, const char *str);
void		ft_usleep(long p_time);
void		free_all(t_data *data);
void		*dead_monitor(t_data *data);
void		threading(t_philo *philo, t_argc val);
long long	get_time(t_data *data);

#endif
