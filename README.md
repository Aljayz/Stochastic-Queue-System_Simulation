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
├── include/ # Header files
│ ├── Event.h # Event class definition
│ ├── QueueSimulation.h # Main simulation class
│ ├── RandomExpoMean.h # Exponential random number generator
│ └── Server.h # Server structure definition
├── src/ # Source files
│ ├── main.cpp # Main program and scenarios
│ ├── QueueSimulation.cpp # Simulation implementation
│ └── RandomExpoMean.cpp # Random generator implementation
└── README.md # This file
```

In the src directory, run this command in terminal:
```
g++ main.cpp QueueSimulation.cpp RandomExpoMean.cpp -o main -I../include
```
