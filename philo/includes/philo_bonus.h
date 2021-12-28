/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksy <ksy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 21:32:44 by ksy               #+#    #+#             */
/*   Updated: 2021/12/23 21:32:44 by ksy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_argc
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_must_eat;
}	t_argc;

typedef struct s_data
{
	sem_t	*fork;
	sem_t	*print;
	sem_t	*must_eat;
	int		dead;
	int		flag;
	int		*cnt;
	t_argc	*info;
}	t_data;

typedef struct s_philo
{
	struct timeval	start;
	struct timeval	last;
	struct timeval	end;
	int				left_fork;
	int				right_fork;
	int				index;
	t_data			*data;
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
void	ft_usleep(long p_time);
void	left_fork(t_philo *philo, int index);
void	right_fork(t_philo *philo, int index);

#endif