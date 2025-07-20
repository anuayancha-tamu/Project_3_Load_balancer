/**
 * @file main.cpp
 * @brief Entry point for the Load Balancer simulation.
 */

#include <iostream>
#include "LoadBalancer.h"

/**
 * @brief Main function to initialize and run the Load Balancer simulation.
 *
 * Prompts the user for the number of web servers and clock cycles,
 * creates a LoadBalancer instance, fills the request queue, and runs the simulation.
 *
 * @return int Exit status code.
 */
int main() {
    int numServers;
    int numCycles;

    std::cout << "Enter number of web servers: ";
    std::cin >> numServers;

    std::cout << "Enter number of clock cycles to simulate: ";
    std::cin >> numCycles;

    LoadBalancer lb(numServers);
    lb.fillInitialQueue();
    lb.run(numCycles);

    std::cout << "Simulation complete. Check 'log.txt' for detailed output.\n";

    return 0;
}