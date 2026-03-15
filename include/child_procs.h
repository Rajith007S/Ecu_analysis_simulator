#ifndef CHILD_PROCS_H
#define CHILD_PROCS_H

void sensor_proc();
void stats_analysis(int pipefd);
void ecu_logger(int pipefd);

#endif

