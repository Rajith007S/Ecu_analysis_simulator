#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "child_procs.h"

void ecu_logger(int pipefd)
{
    char buffer[256];

    int fd = open("ecu_log.txt",
                  O_CREAT | O_WRONLY | O_APPEND,
                  0666);

    if(fd < 0)
    {
        perror("log file open failed");
        return;
    }

    while(1)
    {
        read(pipefd, buffer, sizeof(buffer));

        write(fd, buffer, strlen(buffer));
        write(fd, "\n", 1);

        printf("LOG: %s\n", buffer);
    }
}
