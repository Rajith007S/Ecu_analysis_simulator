#ifndef IPC_H
#define IPC_H
#include <mqueue.h>
#include "ecu_var.h"

sensor_data* create_shm();
mqd_t create_mq();

#endif 
