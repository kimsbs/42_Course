#ifndef _PHILO_H_
#define _PHILO_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/time.h>

typedef struct s_argc
{
    int num_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_must_eat;
}   t_argc;

typedef struct s_data
{
    sem_t   *fork;
    sem_t   *count;
    sem_t   *print;
    struct timeval  start;
    struct timeval  last;
    struct timeval  end;
    int             dead;
    int             cnt;
    t_argc          *info;
} t_data;

typedef struct s_philo
{
    int left_fork;
    int right_fork;
    int index;
    t_data *data;
    pthread_t thread;
} t_philo;

int     ft_strlen(char *s);
int     ft_atoi(char *s);
void    ft_putchar(char c);
void    ft_putstr(char *s);
void    argc_error();
t_philo *init_philo(char **argv, t_argc *val, t_data *data);
void    *get_fork(void *args);
void    eating(t_philo *philo, int index);
void    sleeping(t_philo *philo, int index);
void    thinking(t_philo *philo, int index);
int     u_time(t_philo *philo, int flag);
int     is_end(t_philo *philo, int timeval, int flag);
int     data_free(t_data *data);

#endif