#include "philo_bonus.h"

int u_time(t_philo *philo, int flag)
{
    int diff;
    struct timeval  time;
    diff = 0;
    gettimeofday(&(philo->data->end), NULL);
    if (flag) // diff with start time
        time = philo->data->start;
    else //diff with last meal
        time = philo->data->last;
    diff += philo->data->end.tv_sec - time.tv_sec;
    diff *= 1000000;
    diff += philo->data->end.tv_usec - time.tv_usec;
    return (diff / 1000);
}

void thinking(t_philo *philo, int index)
{
    int timeval;

    timeval = u_time(philo, 0);
    if (!is_end(philo, timeval))
    {
        timeval = u_time(philo, 1);
        printf("%dms %d philo thinking\n", timeval, index);
    }
    sem_post(philo->data->print);
}

void sleeping(t_philo *philo, int index)
{
    int sleep;
    int timeval;
    int flag;

    flag = 0;
    timeval = u_time(philo, 0);
    if (!is_end(philo, timeval))
    {
        flag = 1;
        sleep = philo->data->info->time_to_sleep;
        timeval = u_time(philo, 1);
        usleep(sleep * 1000);
        printf("%dms %d philo sleeping\n", timeval, index);
    }
    if (flag) 
        thinking(philo, index);
    else
        sem_post(philo->data->print);
}

void eating(t_philo *philo, int index)
{
    int eat;
    int timeval;
    int flag;

    flag = 0;
    sem_wait(philo->data->print);
    timeval = u_time(philo, 0);
    if (!is_end(philo, 0))
    {
        flag = 1;
        philo->data->last = philo->data->end;
        philo->data->cnt += 1;
        sem_post(philo->data->must_eat);
        timeval = u_time(philo, 1);
        eat = philo->data->info->time_to_eat;
        usleep(eat * 1000);
        printf("%dms %d philo eating\n", timeval, index);
    }
    sem_post(philo->data->fork);
    sem_post(philo->data->fork);
    if (flag) 
        sleeping(philo, index);
    else
        sem_post(philo->data->print);
}