#include "philo.h"

void    val_init(char **argv, t_argc *val)
{
    val->num_of_philo = ft_atoi(argv[1]);
    val->time_to_die = ft_atoi(argv[2]);
    val->time_to_eat = ft_atoi(argv[3]);
    val->time_to_sleep = ft_atoi(argv[4]);
    if(argv[5])
        val->number_of_must_eat = ft_atoi(argv[5]);
    else
        val->number_of_must_eat = val->num_of_philo + 1;
}

int    init_data(char **argv, t_argc *val, t_data *data)
{
    int i;

    i = -1;
    val_init(argv, val);
    data->fork = sem_open("fork", O_CREAT|O_EXCL , 0644, val->num_of_philo);
    data->count = sem_open("count", O_CREAT|O_EXCL, 0644, 1);
    data->print = sem_open("print", O_CREAT|O_EXCL, 0644, 1);
    data->info = val;
    data->cnt = 0;
    data->dead = 0;
    gettimeofday(&(data->start), NULL);
    data->last = data->start;
    return (1);
}

t_philo *init_philo(char **argv, t_argc *val, t_data *data)
{
    int     i;
    t_philo *philo;

    i = -1;
    if(!init_data(argv, val, data))
        return (0);
    philo = (t_philo *)malloc(sizeof(t_philo) * val->num_of_philo);
    if(!philo)
    {
        //data_free(data);
        return (0);
    }
    while(++i < val->num_of_philo)
    {
        philo[i].left_fork = 0;
        philo[i].right_fork = 0;
        philo[i].index = i;
        philo[i].data = data;
    }
    return (philo);
}