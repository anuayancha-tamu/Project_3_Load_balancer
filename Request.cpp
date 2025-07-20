#include "Request.h"
#include <cstdlib>
#include <sstream>
#include <random>

/**
 * @brief Generates a random IPv4 address as a string.
 * 
 * @return A randomly generated IP address in the format "X.X.X.X".
 */
std::string generateRandomIP() {
    std::ostringstream ip;
    for (int i = 0; i < 4; ++i) {
        ip << (rand() % 256);
        if (i < 3) ip << ".";
    }
    return ip.str();
}

/**
 * @brief Default constructor that initializes a request with random IPs and a random processing time.
 */
Request::Request() {
    ip_in = generateRandomIP();
    //ip_in = "192.168.1.100"; // test block
    ip_out = generateRandomIP();
    time_required = rand() % 10 + 1;
}

/**
 * @brief Constructs a request with specified input/output IP addresses and processing time.
 * 
 * @param in The incoming IP address.
 * @param out The outgoing IP address.
 * @param time The processing time required.
 */
Request::Request(std::string in, std::string out, int time)
    : ip_in(in), ip_out(out), time_required(time) {}