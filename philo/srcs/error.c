#include "philo.h"

void    argc_error()
{
    ft_putstr("input this: ");
    ft_putstr("./philo [number_of_philosophers] [time_to_die] [time_to_eat] ");
    ft_putstr("[time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
}
