#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <mqueue.h>
#include <time.h>
#include "ipc.h"
#include "child_procs.h"

sensor_data *ecu_stats;
mqd_t msg_q;
pthread_mutex_t lock;

void* rpm_stat()
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        ecu_stats->rpm = rand()%6500 ;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void* fuel_stat()
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        ecu_stats->fuel = rand()%100;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void* temp_stat()
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        ecu_stats->temp = rand()%120;
        pthread_mutex_unlock(&lock);
        sleep(1);
    }
    return NULL;
}

void sensor_proc()
{
    pthread_t task1, task2, task3;

    srand(time(NULL));

    ecu_stats = create_shm();
    msg_q = create_mq();

    pthread_mutex_init(&lock,NULL);

    pthread_create(&task1,NULL,rpm_stat,NULL);
    pthread_create(&task2,NULL,fuel_stat,NULL);
    pthread_create(&task3,NULL,temp_stat,NULL);

    sensor_data mqdata;

    while(1)
    {
        pthread_mutex_lock(&lock);
        mqdata = *ecu_stats;
        pthread_mutex_unlock(&lock);

        mq_send(msg_q,(char*)&mqdata,sizeof(sensor_data),0);

        sleep(1);
    }
}
