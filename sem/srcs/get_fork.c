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
        sem_wait(philo->data->print);
        printf("=====%dms %d philo is died====\n", timeval / 1000, philo->index);
        sem_post(philo->data->print);
        return (1);
    }
    return (0);
}

void right_fork(t_philo *philo, int index)
{
    int timeval;

    if (is_end(philo, 0, 0))
        return;
    sem_wait(philo->data->fork);
    philo->right_fork = 1;
    sem_wait(philo->data->print);
    timeval = u_time(philo, 1);
    if (!is_end(philo, timeval, 0))
        printf("%dms %d philo get right fork\n", timeval, index);
    sem_post(philo->data->print);
}

void left_fork(t_philo *philo, int index)
{
    int timeval;

    if (is_end(philo, 0, 0))
        return;
    sem_wait(philo->data->fork);
    philo->left_fork = 1;
    sem_wait(philo->data->print);
    timeval = u_time(philo, 1);
    if (!is_end(philo, timeval, 0))
        printf("%dms %d philo get left fork\n", timeval, index);
    sem_post(philo->data->print);
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