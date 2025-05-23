# Stochastic-Queue-System_Simulation
A discrete-event simulation of a single or multi-server queueing system with exponential inter-arrival and service times.

## Project Description

This C++ program simulates a queueing system with:
- Configurable number of servers
- Exponential inter-arrival times
- Exponential service times
- Finite queue capacity
- Comprehensive statistics collection

The simulation models common queueing scenarios like:
- Balanced systems (λ = μ)
- Overloaded systems (λ > μ)
- Underloaded systems (λ < μ)

Key metrics calculated:
- System utilization
- Average queue length
- Average waiting time
- Rejection rates
- Per-server statistics

## File Structure
```
Stochastic-Queue-System-Simulation/
├── include/                   # Header files
│ ├── Event.h                  # Event class definition
│ ├── QueueSimulation.h        # Main simulation class
│ ├── RandomExpoMean.h         # Exponential random number generator
│ └── Server.h                 # Server structure definition
├── src/                       # Source files
│ ├── main.cpp                 # Main program and scenarios
│ ├── QueueSimulation.cpp      # Simulation implementation
│ └── RandomExpoMean.cpp       # Random generator implementation
└── README.md                  # This file
```

In the src directory, run this command in terminal:
```
g++ main.cpp QueueSimulation.cpp RandomExpoMean.cpp -o main -I../include & main.exe
```

Sample Output:
```
=== Balanced System (╬╗ = ╬╝) ===
Parameters:
- Inter-arrival time mean: 1
- Service duration mean: 1
- Number of servers: 5

SYSTEM STATISTICS
----------------
Simulation duration: 999869.5403 units
Total customers arrived: 1000000
Total customers served: 999997
Total customers rejected: 3
Rejection rate: 0.0003%

QUEUE STATISTICS
----------------
Average queue length: 0.0009
Average waiting time: 0.0009
Maximum queue size reached: 5

SERVER STATISTICS
-----------------
System utilization: 20.0001%

Server #0:
  Customers served: 500055
  Utilization: 50.0709%
  Busy time: 500643.5097 units

Server #1:
  Customers served: 301120
  Utilization: 30.0549%
  Busy time: 300510.2564 units

Server #2:
  Customers served: 138078
  Utilization: 13.8264%
  Busy time: 138245.8143 units

Server #3:
  Customers served: 47710
  Utilization: 4.7475%
  Busy time: 47468.7589 units

Server #4:
  Customers served: 13034
  Utilization: 1.3006%
  Busy time: 13004.2214 units





=== Overloaded System (╬╗ > ╬╝) ===
Parameters:
- Inter-arrival time mean: 0.5000
- Service duration mean: 1.0000
- Number of servers: 5

SYSTEM STATISTICS
----------------
Simulation duration: 499883.1284 units
Total customers arrived: 1000000
Total customers served: 999606
Total customers rejected: 394
Rejection rate: 0.0394%

QUEUE STATISTICS
----------------
Average queue length: 0.0381
Average waiting time: 0.0190
Maximum queue size reached: 5

SERVER STATISTICS
-----------------
System utilization: 39.9221%

Server #0:
  Customers served: 338256
  Utilization: 67.3691%
  Busy time: 336766.9399 units

Server #1:
  Customers served: 272307
  Utilization: 54.3773%
  Busy time: 271823.1614 units

Server #2:
  Customers served: 195934
  Utilization: 39.2666%
  Busy time: 196287.0784 units

Server #3:
  Customers served: 124595
  Utilization: 24.8108%
  Busy time: 124025.1004 units

Server #4:
  Customers served: 68514
  Utilization: 13.7868%
  Busy time: 68917.8968 units





=== Underloaded System (╬╗ < ╬╝) ===
Parameters:
- Inter-arrival time mean: 2.0000
- Service duration mean: 1.0000
- Number of servers: 5

SYSTEM STATISTICS
----------------
Simulation duration: 2001634.0483 units
Total customers arrived: 1000000
Total customers served: 1000000
Total customers rejected: 0
Rejection rate: 0.0000%

QUEUE STATISTICS
----------------
Average queue length: 0.0000
Average waiting time: 0.0001
Maximum queue size reached: 5

SERVER STATISTICS
-----------------
System utilization: 9.9899%

Server #0:
  Customers served: 667186
  Utilization: 33.3499%
  Busy time: 667542.7616 units

Server #1:
  Customers served: 255989
  Utilization: 12.7738%
  Busy time: 255684.7917 units

Server #2:
  Customers served: 64031
  Utilization: 3.1846%
  Busy time: 63744.7281 units

Server #3:
  Customers served: 11314
  Utilization: 0.5657%
  Busy time: 11322.5759 units

Server #4:
  Customers served: 1480
  Utilization: 0.0756%
  Busy time: 1513.6549 units
```
