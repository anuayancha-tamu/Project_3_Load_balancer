#include "WebServer.h"
#include <iostream>

/**
 * @brief Constructs a WebServer and initializes it as idle.
 */
WebServer::WebServer() {
    busy = false;
    time_left = 0;
}

/**
 * @brief Assigns a new request to the server and sets its processing time.
 * 
 * @param req The request to process.
 */
void WebServer::assignRequest(const Request& req) {
    current_request = req;
    time_left = req.time_required;
    busy = true;
}

/**
 * @brief Simulates one clock cycle by decrementing time left on the current request.
 * Marks the server as free when the request completes.
 */
void WebServer::tick() {
    if (busy) {
        time_left--;
        if (time_left <= 0) {
            busy = false;
        }
    }
}

/**
 * @brief Checks whether the server is currently idle.
 * 
 * @return True if the server is free; false otherwise.
 */
bool WebServer::isFree() const {
    return !busy;
}

/**
 * @brief Gets the number of cycles remaining for the current request.
 * 
 * @return Remaining time in clock cycles.
 */
int WebServer::getTimeLeft() const {
    return time_left;
}

/**
 * @brief Prints the server’s current status to the console.
 */
void WebServer::printStatus() const {
    if (busy) {
        std::cout << "Processing request from " << current_request.ip_in
                  << " to " << current_request.ip_out
                  << " with " << time_left << " cycles left.\n";
    } else {
        std::cout << "Server is idle.\n";
    }
}