#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <mqueue.h>
#include <unistd.h>
#include "ipc.h"

sensor_data* create_shm(){

    int fd = shm_open(SHM_NAME,O_CREAT | O_RDWR,0666);
    ftruncate(fd,sizeof(sensor_data));
    return mmap(0,sizeof(sensor_data),
                PROT_READ | PROT_WRITE,
                MAP_SHARED,fd,0);
}

mqd_t create_mq(){

    struct mq_attr attr;
    
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(sensor_data);
    attr.mq_curmsgs = 0;
    
    return mq_open(MQ_NAME, O_CREAT | O_RDWR , 0666, &attr);
}
                            
    
