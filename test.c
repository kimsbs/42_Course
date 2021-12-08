#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
 
pthread_mutex_t mutex;

typedef struct philo{
    pthread_t   p;
    int         left_fork;
    int         right_fork;
    int         index;
}philosophers;

typedef struct data{
    int             fork[5];
    philosophers    p[5];
}t_data;

void* get_fork(void *data){
        pthread_t   tid;
        int         index;
        tid = pthread_self();
 
        index = data.index;
        printf("\ttid:%x\n",tid);
        pthread_mutex_lock(&mutex);
        pthread_mutex_unlock(&mutex);
}

void    init_data(t_data *data)
{
    int i;
    for(i = 0 ; i < 5 ; i++)
        data->fork[i] = 1;
    for(i = 0 ; i < 5 ; i++)
    {
        data->p[i].left_fork = data->p[i].right_fork = 0;
        data->p[i].index = i;
    }
} 

int main(){
        t_data  data;  
        int     i;

        init_data(&data);

        pthread_mutex_init(&mutex, NULL);

        for(i = 0 ; i < 5 ; i++)
            pthread_create(&data.p[i], NULL,get_fork, &data);
        
        for(i = 0 ; i < 5 ; i++)
            pthread_join(&data.p[i], NULL);
}