#ifndef QUEUE_SIMULATION_H
#define QUEUE_SIMULATION_H

#include <queue>
#include <vector>
#include <iomanip>
#include <iostream>

#include "Event.h"
#include "Server.h"
#include "randomExpoMean.h"

class QueueSimulation {
public:
    QueueSimulation(double interArrivalMean,
                   double serviceDurationMean,
                   size_t maxCustomersToServe = 1000,
                   size_t numberOfServers = 1,
                   size_t maxWaitingQueue = 5);
    
    void run();
    void printStatistics() const;

private:
    // Simulation components
    RandomExpoMean interArrival;
    RandomExpoMean serviceDuration;
    std::priority_queue<Event, std::vector<Event>, std::greater<Event>> eventQueue;
    std::queue<double> waitingCustomers;
    std::vector<Server> servers;
    
    // Configuration
    size_t maxQueue;
    size_t numServers;
    size_t maxCustomers;
    
    // State variables
    double currentTime = 0.0;
    double simulationStartTime = 0.0;
    
    // Statistics
    double totalQueueLength = 0.0;
    double totalDelay = 0.0;
    double totalServerBusy = 0.0;
    size_t totalArrivals = 0;
    size_t totalServiced = 0;
    size_t totalRejected = 0;

    // Helper methods
    void processArrival();
    void processDeparture(size_t serverId);
    void scheduleArrival();
    void scheduleDeparture(size_t id);
};
#endif // QUEUE_SIMULATION_H