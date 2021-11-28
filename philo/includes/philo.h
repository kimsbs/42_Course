#ifndef _PHILO_H_
#define _PHILO_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

typedef struct s_argc
{
    int num_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_must_eat;
}   t_argc;

int     ft_strlen(char *s);
int     ft_atoi(char *s);
void    ft_putchar(char c);
void    ft_putstr(char *s);
void    argc_error();

#endif