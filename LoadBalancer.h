#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <vector>
#include <fstream>
#include "WebServer.h"
#include "RequestQueue.h"
#include "Firewall.h"

/**
 * @class LoadBalancer
 * @brief Simulates a load balancer managing multiple web servers and a queue of requests.
 */
class LoadBalancer {
private:
    std::vector<WebServer*> servers;  ///< List of dynamically allocated web servers
    RequestQueue requestQueue;        ///< Queue holding incoming requests
    Firewall firewall;
    int clock;                        ///< Current clock cycle of the simulation
    std::ofstream logFile;            ///< Output file stream for logging simulation data

public:
    /**
     * @brief Constructor to initialize the load balancer with a given number of servers.
     * @param numServers Number of web servers to start with.
     */
    LoadBalancer(int numServers);

    /**
     * @brief Destructor to clean up dynamically allocated resources.
     */
    ~LoadBalancer();

    /**
     * @brief Simulates one clock cycle of activity in the system.
     */
    void tick();

    /**
     * @brief Adds a new request to the queue.
     * @param req The request to add.
     */
    void addRequest(const Request& req);

    /**
     * @brief Pre-fills the queue with requests based on number of servers.
     */
    void fillInitialQueue();

    /**
     * @brief Prints the current state of the load balancer to the terminal.
     */
    void printState() const;

    /**
     * @brief Logs the current state of the load balancer to the log file.
     */
    void logState();

    /**
     * @brief Runs the load balancer simulation for a given number of clock cycles.
     * @param cycles Number of cycles to run.
     */
    void run(int cycles);
};

#endif