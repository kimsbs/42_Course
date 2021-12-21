#include "philo.h"

void    free_all(t_philo *philo, t_data *data)
{
    int max;

    max = philo->data->info->num_of_philo;
    for (int i = 0; i < max; i++)
        pthread_mutex_destroy(&data->mutex[i]);
    pthread_mutex_destroy(&data->print);
    pthread_mutex_destroy(&data->die);
    free(data->mutex);
    free(data);
    free(philo);
}

void    lets_doing(char **argv)
{
    t_argc  val;
    t_philo *philo;
    t_data  *data;
    
    data = (t_data *)malloc(sizeof(t_data));
    if(!data)
        return ;
    philo = init_philo(argv, &val, data);
    if(!philo)
        return ;
    for (int i = 0; i < val.num_of_philo; i++)
        pthread_create(&philo[i].thread, NULL, &get_fork, &philo[i]);
    for (int i = 0; i < val.num_of_philo; i++)
        pthread_join(philo[i].thread, NULL);
    printf("%d\n", data->cnt);
    free_all(philo, data);
}

int main(int argc, char** argv)
{
    if(!(argc == 6 || argc == 5))
    {
        argc_error();
        return (0);
    }
    lets_doing(argv);
    system("leaks philo");
}