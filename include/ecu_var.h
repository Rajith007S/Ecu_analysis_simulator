#ifndef ECU_VAR_H
#define ECU_VAR_H

#define SHM_NAME   "/ecu_shm"
#define MQ_NAME     "/ecu_mq"

typedef struct
{
    int rpm;
    int fuel;
    int temp;
} sensor_data;

#endif

