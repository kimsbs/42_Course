#include "philo.h"

void    val_init(char **argv, t_argc *val)
{
    val->num_of_philo = ft_atoi(argv[1]);
    val->time_to_die = ft_atoi(argv[2]);
    val->time_to_eat = ft_atoi(argv[3]);
    val->time_to_sleep = ft_atoi(argv[4]);
    val->number_of_must_eat = ft_atoi(argv[5]);
}

void    print_val(t_argc val)
{
    printf("%d ", val.num_of_philo);
    printf("%d ", val.time_to_die);
    printf("%d ", val.time_to_eat);
    printf("%d ", val.time_to_sleep);
    printf("%d \n", val.number_of_must_eat);
}

int main(int argc, char** argv)
{
    struct timeval start;
    struct timeval end;
    t_argc val;
    double difftime;

    gettimeofday(&start, NULL);
    if(argc != 6)
    {
        argc_error();
        return (0);
    }
    val_init(argv, &val);
    print_val(val);
    gettimeofday(&end, NULL);
    difftime = (end.tv_usec - start.tv_usec);
    printf("%.0f", difftime);
}