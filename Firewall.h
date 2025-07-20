#ifndef FIREWALL_H
#define FIREWALL_H

#include <string>
#include <vector>
#include <unordered_set>

/**
 * @class Firewall
 * @brief Handles IP-based request blocking to simulate a basic firewall mechanism.
 *
 * This class manages a list of blocked IP addresses. Incoming requests from these
 * addresses will be denied by the LoadBalancer.
 */
class Firewall {
private:
    std::unordered_set<std::string> blockedIPs;  ///< A set containing blocked IP addresses.

public:
    /**
     * @brief Constructs a Firewall and preloads it with a list of default blocked IPs.
     */
    Firewall();

    /**
     * @brief Checks if the given IP address is currently blocked.
     * @param ip The IP address to check.
     * @return true if the IP is blocked, false otherwise.
     */
    bool isBlocked(const std::string& ip) const;

    /**
     * @brief Adds an IP address to the blocked list.
     * @param ip The IP address to block.
     */
    void blockIP(const std::string& ip);

    /**
     * @brief Removes an IP address from the blocked list.
     * @param ip The IP address to unblock.
     */
    void unblockIP(const std::string& ip);
};

#endif