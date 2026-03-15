#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <mqueue.h>
#include "ipc.h"
#include "child_procs.h"

void stats_analysis(int pipefd)
{
    mqd_t mq_r = create_mq();
    
    sensor_data stat_r;
    char msg[200];
    
    while(1)
    {
        mq_receive(mq_r,(char*)&stat_r,sizeof(sensor_data),NULL);
        

        sprintf(msg,
        "RPM:%d Fuel:%d Temp:%d",
        stat_r.rpm,stat_r.fuel,stat_r.temp);

        if(stat_r.temp > 100)
            strcat(msg," ALERT:OVERHEAT");

        if(stat_r.rpm > 5500)
           printf(" ALERT:HIGH RPM");
            
        if(stat_r.fuel < 20)
            printf(" ALERT:FUEL LOW");
            
        write(pipefd,msg,128);

        sleep(1);
    }
}
