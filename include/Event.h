#ifndef EVENT_H
#define EVENT_H

#include <functional>

enum class EventType {
    ARRIVAL,
    DEPARTURE
};

class Event {
public:
    Event(EventType type, double time, size_t serverID = -1)
        : time_(time), type_(type), serverID_(serverID) {}

    // Accessors
    double getTime() const { return time_; }
    EventType getType() const { return type_; }
    size_t getID() const { return serverID_; }

    // Comparison for priority queue
    bool operator>(const Event& other) const {
        return time_ > other.time_;
    }

private:
    double time_;
    EventType type_;
    size_t serverID_;
};

#endif // EVENT_H