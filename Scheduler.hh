#pragma once

#include <queue>
#include <string>
#include <sstream>
#include <functional>
#include "Process.hh"

#define MAX_PRIORITY INT32_MAX

class Scheduler {
public:
	Scheduler() { };
	virtual ~Scheduler() = default;
	virtual void add_new_process(std::stringstream&) = 0;
	virtual std::string make_tick() { };
	virtual bool is_finished() { };
    virtual void arrive() = 0;
    struct ComparePriority {
        bool operator()(Process& p1, Process& p2) {
            return p1.get_priority() != p2.get_priority() ?
                   p1.get_priority() < p2.get_priority() :
                   (p1.get_arrival_time() != p2.get_arrival_time() ?
                    p1.get_arrival_time() > p2.get_arrival_time() :
                    p1.get_id() > p2.get_id());
        }
    };

    struct CompareArrival {
        bool operator()(Process& p1, Process& p2) {
            return p1.get_arrival_time() != p2.get_arrival_time() ?
                   p1.get_arrival_time() > p2.get_arrival_time() :
                   p1.get_id() > p2.get_id();
        }
    };

protected:
    uint32_t time;
    std::priority_queue<Process, std::vector<Process>, CompareArrival> arrival_queue;
    std::priority_queue<Process, std::vector<Process>, ComparePriority> queue;
};
