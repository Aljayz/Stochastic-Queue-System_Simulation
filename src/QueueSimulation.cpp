
#include "../include/QueueSimulation.h"

QueueSimulation::QueueSimulation(double interArrivalMean,
                               double serviceDurationMean,
                               size_t maxCustomersToServe,
                               size_t numberOfServers,
                               size_t maxWaitingQueue)
    : interArrival(interArrivalMean),
      serviceDuration(serviceDurationMean),
      maxCustomers(maxCustomersToServe),
      numServers(numberOfServers),
      maxQueue(maxWaitingQueue) {
    servers.resize(numServers);
    for (size_t i = 0; i < numServers; i++) {
        servers[i].id = i;
    }
}
void QueueSimulation::run() {

    simulationStartTime = currentTime;
    
    // Schedule the first arrival
    scheduleArrival();

    while (!eventQueue.empty()) {
        Event ev = eventQueue.top();
        eventQueue.pop();

        // Update time-weighted statistics
        double timeElapsed = ev.getTime() - currentTime;
        if (timeElapsed > 0) {
            totalQueueLength += waitingCustomers.size() * timeElapsed;
            
            for (auto& server : servers) {
                if (server.status == ServerStatus::BUSY) {
                    server.totalBusyTime += timeElapsed;
                    totalServerBusy += timeElapsed;
                }
            }
            
            currentTime = ev.getTime();
        }

        // Process the event
        ev.getType() == EventType::ARRIVAL ? processArrival() : processDeparture(ev.getID());
    }

    // Process any remaining waiting customers for final delay calculation
    while (!waitingCustomers.empty()) {
        totalDelay += (currentTime - waitingCustomers.front());
        waitingCustomers.pop();
    }
}

void QueueSimulation::processArrival() {
    ++totalArrivals;

    // Schedule next arrival if we haven't reached max customers
    if (totalArrivals < maxCustomers) {
        scheduleArrival();
    }

    // Try to assign to an idle server
    for (auto& server : servers) {
        if (server.status == ServerStatus::IDLE) {
            server.status = ServerStatus::BUSY;
            scheduleDeparture(server.id);
            return;
        }
    }

    // All servers busy - enqueue or reject
    if (waitingCustomers.size() < maxQueue) {
        waitingCustomers.push(currentTime);
    } else {
        ++totalRejected;
    }
}

void QueueSimulation::processDeparture(size_t serverId) {
    ++totalServiced;
    Server& server = servers[serverId];
    ++server.totalCustomer;
    server.status = ServerStatus::IDLE;

    if (!waitingCustomers.empty()) {
        // Serve next customer in queue
        double arrivalTime = waitingCustomers.front();
        waitingCustomers.pop();
        totalDelay += (currentTime - arrivalTime);
        
        server.status = ServerStatus::BUSY;
        scheduleDeparture(serverId);
    }
}

void QueueSimulation::scheduleArrival() {
    eventQueue.push(Event(EventType::ARRIVAL, currentTime + interArrival.getValue()));
}

void QueueSimulation::scheduleDeparture(size_t id) {
    eventQueue.push(Event(EventType::DEPARTURE, 
                         currentTime + serviceDuration.getValue(), 
                         id));
}

void QueueSimulation::printStatistics() const {
    double totalSimulationTime = currentTime - simulationStartTime;
    
    if (totalSimulationTime <= 0 || totalServiced == 0) {
        std::cout << "\nInsufficient data for statistics.\n";
        return;
    }

    // System statistics
    std::cout << "\nSYSTEM STATISTICS\n";
    std::cout << "----------------\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Simulation duration: " << totalSimulationTime << " units\n";
    std::cout << "Total customers arrived: " << totalArrivals << "\n";
    std::cout << "Total customers served: " << totalServiced << "\n";
    std::cout << "Total customers rejected: " << totalRejected << "\n";
    std::cout << "Rejection rate: " 
              << (static_cast<double>(totalRejected) / totalArrivals * 100) << "%\n";

    // Queue statistics
    double avgQueueLength = totalQueueLength / totalSimulationTime;
    size_t customersInSystem = totalArrivals - totalRejected;
    double avgDelay = customersInSystem > 0 ? (totalDelay / customersInSystem) : 0.0;
    
    std::cout << "\nQUEUE STATISTICS\n";
    std::cout << "----------------\n";
    std::cout << "Average queue length: " << avgQueueLength << "\n";
    std::cout << "Average waiting time: " << avgDelay << "\n";
    std::cout << "Maximum queue size reached: " << maxQueue << "\n";

    // Server statistics
    double systemUtilization = totalServerBusy / (numServers * totalSimulationTime);
    
    std::cout << "\nSERVER STATISTICS\n";
    std::cout << "-----------------\n";
    std::cout << "System utilization: " << (systemUtilization * 100) << "%\n";
    
    for (const auto& server : servers) {
        double serverUtilization = server.totalBusyTime / totalSimulationTime;
        
        std::cout << "\nServer #" << server.id << ":\n";
        std::cout << "  Customers served: " << server.totalCustomer << "\n";
        std::cout << "  Utilization: " << (serverUtilization * 100) << "%\n";
        std::cout << "  Busy time: " << server.totalBusyTime << " units\n";
    }
}