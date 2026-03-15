#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
#include "child_procs.h"

int pipefd[2];

void handler(int sig)
{
    printf("\nECU system shutting down\n");
    exit(0);
}

int main()
{
    signal(SIGINT,handler);

    pipe(pipefd);

    pid_t sensor = fork();

    if(sensor==0)
    {
        close(pipefd[0]);
        close(pipefd[1]);
        sensor_proc();
    }

    pid_t analysis = fork();

    if(analysis==0)
    {
        close(pipefd[0]);
        stats_analysis(pipefd[1]);
    }

    pid_t logger = fork();

    if(logger==0)
    {
        close(pipefd[1]);
        ecu_logger(pipefd[0]);
    }

    close(pipefd[0]);
    close(pipefd[1]);

    wait(NULL);
    wait(NULL);
    wait(NULL);

    return 0;
}
