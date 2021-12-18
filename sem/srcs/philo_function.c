#include "philo.h"

int u_time(t_philo *philo, int flag)
{
    int diff;

    diff = 0;
    if (flag)
    {
        gettimeofday(&(philo->data->end), NULL);
        diff += philo->data->end.tv_sec - philo->data->start.tv_sec;
        diff *= 1000000;
        diff += philo->data->end.tv_usec - philo->data->start.tv_usec;
    }
    else
    {
        gettimeofday(&(philo->data->end), NULL);
        diff += philo->data->end.tv_sec - philo->data->last.tv_sec;
        diff *= 1000000;
        diff += philo->data->end.tv_usec - philo->data->last.tv_usec;
    }
    return (diff / 1000);
}

void thinking(t_philo *philo, int index)
{
    int timeval;

    timeval = u_time(philo, 1);
    if (is_end(philo, timeval, 0))
        return;
    sem_wait(philo->data->print);
    if (!is_end(philo, timeval, 0))
        printf("%dms %d philo thinking\n", timeval, index);
    sem_post(philo->data->print);
}

void sleeping(t_philo *philo, int index)
{
    int sleep;
    int timeval;

    sleep = philo->data->info->time_to_sleep;
    timeval = u_time(philo, 1);
    if (is_end(philo, 0, 0))
        return;
    sem_wait(philo->data->print);
    if (!is_end(philo, 0, 0))
        printf("%dms %d philo sleeping\n", timeval, index);
    sem_post(philo->data->print);
    usleep(sleep * 1000);
    thinking(philo, index);
}

void eating2(t_philo *philo, int index, int eat, int timeval)
{
    philo->data->last = philo->data->end;
    sem_wait(philo->data->print);
    if (!is_end(philo, 0, 0))
    {
        timeval = u_time(philo, 1);
        printf("%dms %d philo eating\n", timeval, index);
    }
    sem_post(philo->data->print);
    usleep(eat * 1000);
    philo->data->cnt += 1;
    sem_post(philo->data->count);
    sem_post(philo->data->fork);
    sem_post(philo->data->fork);
    sleeping(philo, index);
}

void eating(t_philo *philo, int index)
{
    int eat;
    int timeval;

    eat = philo->data->info->time_to_eat;
    sem_wait(philo->data->count);
    timeval = u_time(philo, 0);
    if (is_end(philo, timeval, 1))
    {
        sem_post(philo->data->count);
        sem_post(philo->data->fork);
        sem_post(philo->data->fork);
    }
    else
        eating2(philo, index, eat, timeval);
}