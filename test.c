#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

int cnt = 0;

typedef struct s_data
{
    pthread_mutex_t mutex[10];
    pthread_mutex_t count;
    //struct s_philo *philo;
} t_data;

typedef struct s_philo
{
    int left_fork;
    int right_fork;
    int index;
    t_data *data;
} t_philo;

void init_data(t_philo *philo, t_data *data)
{
    int i;
    //data->philo = philo;
    for (i = 0; i < 10; i++)
    {
        philo[i].left_fork = philo[i].right_fork = 0;
        philo[i].index = i;
        philo[i].data = data;
    }
    for (i = 0; i < 10; i++)
        pthread_mutex_init(&philo->data->mutex[i], NULL);
    pthread_mutex_init(&philo->data->count, NULL);
}

void right_fork(t_philo *philo, int index)
{
    if (philo->right_fork == 0)
    {
        pthread_mutex_lock(&philo->data->mutex[(index + 1) % 10]);
        philo->right_fork = 1;
        printf("%d philo get right fork\n", index);
    }
}

void left_fork(t_philo *philo, int index)
{
    if (philo->left_fork == 0)
    {
        pthread_mutex_lock(&philo->data->mutex[index]);
        philo->left_fork = 1;
        printf("%d philo get left fork\n", index);
    }
}

void eating(t_philo *philo, int index)
{
    if (philo->right_fork == 1 && philo->left_fork == 1)
    {
        printf("%d philo eating\n", index);
        pthread_mutex_lock(&philo->data->count);
        printf("%d philo sleeping\n", index);
        sleep(1);
        printf("%d philo thinking\n", index);
        philo->left_fork = philo->right_fork = 0;
        cnt++;
        pthread_mutex_unlock(&philo->data->count);
        pthread_mutex_unlock(&philo->data->mutex[index]);
        pthread_mutex_unlock(&philo->data->mutex[(index + 1) % 10]);
        printf("%d philo droped fork\n", index);
    }
}

void *get_fork(void *args)
{
    t_philo *philo;
    int     index;

    philo = args;
    index = philo->index;

    if (index == 0)
    {
        left_fork(philo, index);
        if(philo->left_fork == 1)
            right_fork(philo, index);
    }
    else
    {
        right_fork(philo, index);
        if(philo->right_fork == 1)
            left_fork(philo, index);
    }
    eating(philo, index);
    return (NULL);
}

int main()
{
    t_data data;
    t_philo philo[10];
    pthread_t thread;
    int i;

    init_data(philo, &data);
    
    for (i = 0; i < 10; i++)
        pthread_create(&thread, NULL, &get_fork, &philo[i]);
    pthread_join(thread, NULL);
    
    printf("eatten philo: %d\n", cnt);
}