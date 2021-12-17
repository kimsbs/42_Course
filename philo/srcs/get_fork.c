#include "philo.h"

int is_end(t_philo *philo, int timeval, int flag)
{
    if (philo->data->cnt == philo->data->info->number_of_must_eat)
        return (1);
    if (philo->data->dead)
        return (1);
    if (timeval > philo->data->info->time_to_die && flag)
    {
        philo->data->dead = 1;
        pthread_mutex_lock(&philo->data->print);
        printf("=====%dms %d philo is died====\n", timeval / 1000, philo->index);
        pthread_mutex_unlock(&philo->data->print);
        return (1);
    }
    return (0);
}

void right_fork(t_philo *philo, int index)
{
    int timeval;

    if (is_end(philo, 0, 0))
        return;
    pthread_mutex_lock(&philo->data->mutex[(index + 1) % philo->data->info->num_of_philo]);
    philo->right_fork = 1;
    pthread_mutex_lock(&philo->data->print);
    timeval = u_time(philo, 1);
    if (!is_end(philo, timeval, 0))
        printf("%dms %d philo get right fork\n", timeval, index);
    pthread_mutex_unlock(&philo->data->print);
}

void left_fork(t_philo *philo, int index)
{
    int timeval;

    if (is_end(philo, 0, 0))
        return;
    pthread_mutex_lock(&philo->data->mutex[index]);
    philo->left_fork = 1;
    pthread_mutex_lock(&philo->data->print);
    timeval = u_time(philo, 1);
    if (!is_end(philo, timeval, 0))
        printf("%dms %d philo get left fork\n", timeval, index);
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