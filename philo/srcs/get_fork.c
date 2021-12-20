#include "philo.h"

void put_down_all_fork(t_philo *philo)
{
    int i;

    i = -1;
    while(++i < philo->data->info->num_of_philo)
        pthread_mutex_unlock(&philo->data->mutex[i]);
}

int is_end(t_philo *philo, int timeval)
{
    if (philo->data->cnt == philo->data->info->number_of_must_eat)
    {
        put_down_all_fork(philo);
        philo->data->dead = 1;
        return (1);
    }
    if (philo->data->dead)
        return (1);
    if (timeval > philo->data->info->time_to_die)
    {
        philo->data->dead = 1;
        pthread_mutex_lock(&philo->data->die);
        printf("=====%dms %d philo is died====\n", timeval / 1000, philo->index);
        put_down_all_fork(philo);
        pthread_mutex_unlock(&philo->data->die);
        return (1);
    }
    return (0);
}

void right_fork(t_philo *philo, int index)
{
    int timeval;
    int right_pos;

    right_pos = (index + 1) % philo->data->info->num_of_philo;
    pthread_mutex_lock(&philo->data->mutex[right_pos]);
    pthread_mutex_lock(&philo->data->print);
    timeval = u_time(philo, 0);
    if (!is_end(philo, timeval))
    {
        philo->right_fork = 1;
        timeval = u_time(philo, 1);
        printf("%dms %d philo get right fork\n", timeval, index);
    }
    else
        pthread_mutex_unlock(&philo->data->mutex[right_pos]);
    pthread_mutex_unlock(&philo->data->print);
}

void left_fork(t_philo *philo, int index)
{
    int timeval;

    timeval = u_time(philo, 0);
    pthread_mutex_lock(&philo->data->mutex[index]);
    pthread_mutex_lock(&philo->data->print);
    if (!is_end(philo, timeval))
    {
        philo->left_fork = 1;
        timeval = u_time(philo, 1);
        printf("%dms %d philo get left fork\n", timeval, index);
    }
    else
        pthread_mutex_unlock(&philo->data->mutex[index]);
    pthread_mutex_unlock(&philo->data->print);
}

void *get_fork(void *args)
{
    t_philo *philo;
    int index;

    philo = args;
    index = philo->index;

    if (index % 2)
    {
        left_fork(philo, index);
        if (philo->left_fork == 1)
            right_fork(philo, index);
    }
    else
    {
        right_fork(philo, index);
        if (philo->right_fork == 1)
            left_fork(philo, index);
    }
    if (philo->right_fork == 1 && philo->left_fork == 1)
        eating(philo, index);
    return (NULL);
}