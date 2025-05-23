#include "../include/QueueSimulation.h"

void RunSimulationScenario(const std::string& scenarioName, 
                          double interArrival, 
                          double serviceDuration, 
                          size_t nServer) {
    std::cout << "\n\n\n\n\n=== " << scenarioName << " ===";
    std::cout << "\nParameters:";
    std::cout << "\n- Inter-arrival time mean: " << interArrival;
    std::cout << "\n- Service duration mean: " << serviceDuration;
    std::cout << "\n- Number of servers: " << nServer << "\n";
    
    QueueSimulation simulation(interArrival, serviceDuration, 1000000, nServer, 5);
    simulation.run();
    simulation.printStatistics();
}

int main() {
    // Balanced system (arrival rate = service rate)
    RunSimulationScenario("Balanced System (λ = μ)", 1.0, 1.0, 5);
    
    // Overloaded system (arrival rate > service rate)
    RunSimulationScenario("Overloaded System (λ > μ)", 0.5, 1.0, 5);
    
    // Underloaded system (arrival rate < service rate)
    RunSimulationScenario("Underloaded System (λ < μ)", 2.0, 1.0, 5);
    system("pause");
    return 0;
}
