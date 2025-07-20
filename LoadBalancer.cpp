#include "LoadBalancer.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

/**
 * @brief Constructs a LoadBalancer with the specified number of servers and initializes logging and firewall rules.
 * @param numServers Number of web servers to initialize.
 */
LoadBalancer::LoadBalancer(int numServers) : clock(0) {
    for (int i = 0; i < numServers; ++i) {
        servers.push_back(new WebServer());
    }

    logFile.open("log.txt");
    if (!logFile.is_open()) {
        std::cerr << "Error opening log.txt\n";
    }

    // Example: Pre-block a specific IP for testing purposes
    firewall.blockIP("192.168.1.100");
}

/**
 * @brief Destructor for LoadBalancer. Cleans up allocated web servers and closes the log file.
 */
LoadBalancer::~LoadBalancer() {
    for (auto server : servers) {
        delete server;
    }
    if (logFile.is_open()) {
        logFile.close();
    }
}

/**
 * @brief Simulates a single clock cycle.
 *
 * This includes:
 * - Updating each server's state.
 * - Assigning pending requests to idle servers.
 * - Randomly generating new requests.
 * - Blocking requests from denied IPs using the firewall.
 * - Dynamically adding or removing servers based on queue length.
 * - Logging system state to file.
 */
void LoadBalancer::tick() {
    clock++;

    // Update each server's workload
    for (auto server : servers) {
        server->tick();
    }

    // Assign available requests to idle servers
    for (auto server : servers) {
        if (server->isFree() && !requestQueue.isEmpty()) {
            server->assignRequest(requestQueue.dequeue());
        }
    }

    // Add a new request with some probability
    if (rand() % 5 == 0) {
        Request newReq;
        if (!firewall.isBlocked(newReq.ip_in)) {
            addRequest(newReq);
        } else {
            logFile << "[!] Blocked request from " << newReq.ip_in << "\n";
        }
    }

    // Dynamically add a server if queue size grows too large
    if (requestQueue.size() > static_cast<int>(servers.size()) * 120) {
        servers.push_back(new WebServer());
        logFile << "[+] Added server. Total servers: " << servers.size() << "\n";
    }

    // Dynamically remove a server if underutilized and more than one exists
    if (servers.size() > 1 && requestQueue.size() < static_cast<int>(servers.size()) * 50) {
        delete servers.back();
        servers.pop_back();
        logFile << "[-] Removed server. Total servers: " << servers.size() << "\n";
    }

    // Log the system state
    logState();
}

/**
 * @brief Adds a request to the request queue.
 * @param req The request to be added.
 */
void LoadBalancer::addRequest(const Request& req) {
    requestQueue.enqueue(req);
}

/**
 * @brief Populates the request queue initially based on the number of servers (servers × 100).
 */
void LoadBalancer::fillInitialQueue() {
    int initialSize = servers.size() * 100;
    for (int i = 0; i < initialSize; ++i) {
        requestQueue.enqueue(Request());
    }
}

/**
 * @brief Prints the current state of the load balancer to the terminal.
 *
 * Displays the clock cycle, server status, and current queue size.
 */
void LoadBalancer::printState() const {
    std::cout << "Clock Cycle: " << clock << "\n";
    for (size_t i = 0; i < servers.size(); ++i) {
        std::cout << "Server " << i << ": ";
        servers[i]->printStatus();
    }
    std::cout << "Queue size: " << requestQueue.size() << "\n";
}

/**
 * @brief Logs the current state of the load balancer to the log file.
 *
 * Includes server status (idle or busy with time left) and the size of the request queue.
 */
void LoadBalancer::logState() {
    if (!logFile.is_open()) return;

    logFile << "Clock Cycle: " << clock << "\n";
    for (size_t i = 0; i < servers.size(); ++i) {
        logFile << "Server " << i << ": ";
        if (servers[i]->isFree()) {
            logFile << "Idle";
        } else {
            logFile << "Busy (" << servers[i]->getTimeLeft() << " left)";
        }
        logFile << "\n";
    }

    logFile << "Queue size: " << requestQueue.size() << "\n\n";
}

/**
 * @brief Runs the simulation for a given number of clock cycles.
 * @param cycles The total number of cycles to simulate.
 */
void LoadBalancer::run(int cycles) {
    for (int i = 0; i < cycles; ++i) {
        tick();
    }
}