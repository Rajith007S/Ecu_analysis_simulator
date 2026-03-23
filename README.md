This is an ECU statistic simulation and analysis program built through different POSIX IPCs.

 Project Details :

 The system generates simulated sensor data (RPM, Fuel Level, Engine Temperature),        processes  it, detects anomalies, and logs the results in real time.

 Features:
 
 Multi-process architecture
 Multi-threaded sensor simulation
 POSIX Message Queues for IPC
 Real-time data analysis
 Pipe-based communication
 File logging system
 Signal handling (graceful shutdown)

 Technologies Used :

 C Programming
 POSIX APIs
 pthreads (Multithreading)
 Message Queues (mq_open, mq_send, mq_receive)
 Shared Memory (shm_open, mmap)
 Pipes (pipe, read, write)
 File I/O (open, write, lseek)
 Signals (signal)

 Simulated Parameters:
 Parameter	Range
 RPM	700 – 6000
 Fuel Level	0 – 100 %
 Engine Temperature	60 – 120 °C
 Alert Conditions:

 Overheat → Temp > 100°C
 High RPM → RPM > 5500
 Low Fuel → Fuel < 20%


📂 Project Structure
ECU_sim/
│
├── src/
│   main.c
│   sensor_proc.c
│   stats_analyzer.c
│   ecu_log.c
│   ipc.c
│
├── include/
│   child_procs.h
│   ipc.h
│   ecu_var.h
│
├── Makefile
└── README.md

 Author

 Rajith Shetty
 GitHub: https://github.com/Rajith007S

 📜 License

 This project is for educational purposes.
