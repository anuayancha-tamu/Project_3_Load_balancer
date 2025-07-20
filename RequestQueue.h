#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <queue>
#include "Request.h"

/**
 * @class RequestQueue
 * @brief A wrapper class around std::queue to manage incoming web requests.
 */
class RequestQueue {
private:
    std::queue<Request> queue; ///< Standard queue to hold Request objects

public:
    /**
     * @brief Adds a new request to the end of the queue.
     * @param req The request to enqueue.
     */
    void enqueue(const Request& req);

    /**
     * @brief Removes and returns the request at the front of the queue.
     * @return The request at the front of the queue.
     * @note Behavior is undefined if the queue is empty.
     */
    Request dequeue();

    /**
     * @brief Checks if the request queue is empty.
     * @return True if the queue has no requests, false otherwise.
     */
    bool isEmpty() const;

    /**
     * @brief Gets the number of requests currently in the queue.
     * @return The size of the queue.
     */
    int size() const;
};

#endif // REQUESTQUEUE_H