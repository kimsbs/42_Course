#include "philo.h"

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

    pthread_mutex_lock(&philo->data->print);
    timeval = u_time(philo, 0);
    if (!is_end(philo, timeval))
    {
        timeval = u_time(philo, 1);
        printf("%dms %d philo thinking\n", timeval, index);
    }
    pthread_mutex_unlock(&philo->data->print);
}

void sleeping(t_philo *philo, int index)
{
    int sleep;
    int timeval;
    int flag;

    flag = 0;
    pthread_mutex_lock(&philo->data->print);
    timeval = u_time(philo, 0);
    if (!is_end(philo, timeval))
    {
        flag = 1;
        sleep = philo->data->info->time_to_sleep;
        timeval = u_time(philo, 1);
        usleep(sleep * 1000);
        printf("%dms %d philo sleeping\n", timeval, index);
    }
    pthread_mutex_unlock(&philo->data->print);
    if (flag) 
        thinking(philo, index);
}

void eating(t_philo *philo, int index)
{
    int eat;
    int timeval;
    int flag;
    int right_pos;

    flag = 0;
    right_pos = (index + 1) % philo->data->info->num_of_philo;
    pthread_mutex_lock(&philo->data->print);
    timeval = u_time(philo, 0);
    if (!is_end(philo, 0))
    {
        flag = 1;
        philo->data->last = philo->data->end;
        philo->data->cnt += 1;
        timeval = u_time(philo, 1);
        eat = philo->data->info->time_to_eat;
        usleep(eat * 1000);
        printf("%dms %d philo eating\n", timeval, index);
    }
    pthread_mutex_unlock(&philo->data->mutex[index]);
    pthread_mutex_unlock(&philo->data->mutex[right_pos]);
    pthread_mutex_unlock(&philo->data->print);
    if (flag) 
        sleeping(philo, index);
}