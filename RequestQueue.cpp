#include "RequestQueue.h"

/**
 * @brief Adds a request to the queue.
 * 
 * @param req The request to add.
 */
void RequestQueue::enqueue(const Request& req) {
    queue.push(req);
}

/**
 * @brief Removes and returns the request at the front of the queue.
 * 
 * @return The front request in the queue.
 */
Request RequestQueue::dequeue() {
    Request front = queue.front();
    queue.pop();
    return front;
}

/**
 * @brief Checks whether the queue is empty.
 * 
 * @return True if the queue is empty, false otherwise.
 */
bool RequestQueue::isEmpty() const {
    return queue.empty();
}

/**
 * @brief Returns the number of requests currently in the queue.
 * 
 * @return The size of the queue.
 */
int RequestQueue::size() const {
    return queue.size();
}