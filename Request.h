#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @class Request
 * @brief Represents a web request in the load balancer simulation.
 * 
 * Each request contains input and output IP addresses along with
 * the amount of time it takes to process.
 */
struct Request {
    std::string ip_in;       ///< Incoming IP address
    std::string ip_out;      ///< Outgoing IP address
    int time_required;       ///< Time required to process the request (in clock cycles)

    /**
     * @brief Constructs a Request with randomized IP addresses and processing time.
     */
    Request();

    /**
     * @brief Constructs a Request with specified input/output IPs and time.
     * @param in The incoming IP address.
     * @param out The outgoing IP address.
     * @param time The processing time required.
     */
    Request(std::string in, std::string out, int time);
};

#endif // REQUEST_H