# SJF-CPU-Scheduling-Algorithm-Operating-System
## Description
This repository contains an implementation of the **Shortest Job First (SJF)** scheduling algorithm.

## Usage
Clone the repository and run the code to see the FCFS scheduling in action.


```bash
https://github.com/J-Architect-SUNIL/SJF-CPU-Scheduling-Algorithm-Operating-System.git

## Output
Enter total number of processes: 6
Enter process ID, Arrival time, Burst time for process 1: 1 0 4
Enter process ID, Arrival time, Burst time for process 2: 2 1 2
Enter process ID, Arrival time, Burst time for process 3: 3 2 3
Enter process ID, Arrival time, Burst time for process 4: 4 3 1
Enter process ID, Arrival time, Burst time for process 5: 5 4 5
Enter process ID, Arrival time, Burst time for process 6: 6 5 1
P ID    AT      BT      CT      TAT     WT
1       0       4       4       4       0
2       1       2       8       7       5
3       2       3       11      9       6
4       3       1       5       2       1
5       4       5       16      12      7
6       5       1       6       1       0

Gantt Chart:
P1 -> P4 -> P6 -> P2 -> P3 -> P5
0    4    5    6    8    11    16
