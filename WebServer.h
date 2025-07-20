#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "Request.h"

/**
 * @class WebServer
 * @brief Simulates a web server that can process incoming requests.
 * 
 * Each WebServer instance can be assigned a request and will take
 * a certain number of clock cycles to process it.
 */
class WebServer {
private:
    bool busy;               ///< Indicates whether the server is currently processing a request
    Request current_request; ///< The request currently being processed
    int time_left;           ///< Remaining processing time for the current request

public:
    /**
     * @brief Constructs a new WebServer in an idle state.
     */
    WebServer();

    /**
     * @brief Assigns a request to the server.
     * @param req The request to be processed.
     */
    void assignRequest(const Request& req);

    /**
     * @brief Simulates one clock cycle.
     * Decrements remaining time if the server is busy.
     */
    void tick();

    /**
     * @brief Checks whether the server is free.
     * @return True if the server is idle; false if it is processing a request.
     */
    bool isFree() const;

    /**
     * @brief Gets the remaining time to process the current request.
     * @return Number of clock cycles remaining.
     */
    int getTimeLeft() const;

    /**
     * @brief Prints the current status of the server to the console.
     */
    void printStatus() const;
};

#endif // WEBSERVER_H