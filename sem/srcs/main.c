#include "philo.h"

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
    printf("============\n");
    for (int i = 0; i < val.num_of_philo; i++)
        pthread_create(&philo[i].thread, NULL, &get_fork, &philo[i]);
    for (int i = 0; i < val.num_of_philo; i++)
        pthread_join(philo[i].thread, NULL);
    printf("%d\n", data->cnt);
}

int main(int argc, char** argv)
{
    if(!(argc == 6 || argc == 5))
    {
        argc_error();
        return (0);
    }
    lets_doing(argv);
    //system("leaks philo");
}