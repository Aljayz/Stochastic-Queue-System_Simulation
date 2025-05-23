#ifndef SERVER_H
#define SERVER_H

enum class ServerStatus {
    BUSY,
    IDLE
};

struct Server {
    size_t id = 0;
    ServerStatus status = ServerStatus::IDLE;
    int totalCustomer = 0;
    double totalBusyTime = 0.0;
};

#endif // SERVER_H