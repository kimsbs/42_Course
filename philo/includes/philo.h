/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:39:06 by ksy               #+#    #+#             */
/*   Updated: 2022/02/08 10:46:57 by seungyki         ###   ########.fr       */
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
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
	int				dead;
	int				flag;
	int				*cnt;
	t_argc			*info;
}	t_data;

typedef struct s_philo
{
	int				left_fork;
	int				right_fork;
	int				index;
	struct timeval	start;
	struct timeval	last;
	struct timeval	end;
	t_data			*data;
	pthread_t		thread;
}	t_philo;

int		ft_strlen(char *s);
int		ft_atoi(char *s);
void	argc_error(void);
t_philo	*init_philo(char **argv, t_argc *val, t_data *data);
void	*get_fork(void *args);
void	eating(t_philo *philo, int index);
void	sleeping(t_philo *philo, int index);
void	thinking(t_philo *philo, int index);
int		u_time(t_philo *philo, int flag);
int		is_end(t_philo *philo, int timeval);
int		data_free(t_data *data);
void	left_fork(t_philo *philo, int index);
void	right_fork(t_philo *philo, int index);
void	ft_print_time(t_philo *philo, int index, int timeval, const char *str);
void	ft_usleep(long p_time);

#endif
