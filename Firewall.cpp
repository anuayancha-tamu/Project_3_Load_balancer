#include "Firewall.h"

/**
 * @brief Constructs the Firewall and initializes it with a list of pre-blocked IP addresses.
 *
 * These addresses are hardcoded for demonstration and could be dynamically loaded
 * from a configuration file or database in a future enhancement.
 */
Firewall::Firewall() {
    blockedIPs.insert("192.168.1.100");
    blockedIPs.insert("10.0.0.23");
}

/**
 * @brief Checks whether a given IP address is blocked.
 * @param ip The IP address to check.
 * @return true if the IP is in the blocked list, false otherwise.
 */
bool Firewall::isBlocked(const std::string& ip) const {
    return blockedIPs.find(ip) != blockedIPs.end();
}

/**
 * @brief Adds a new IP address to the block list.
 * @param ip The IP address to block.
 */
void Firewall::blockIP(const std::string& ip) {
    blockedIPs.insert(ip);
}

/**
 * @brief Removes an IP address from the block list.
 * @param ip The IP address to unblock.
 */
void Firewall::unblockIP(const std::string& ip) {
    blockedIPs.erase(ip);
}