#pragma once

#include "Scheduler.hh"

class RoundRobin : public Scheduler {
private:
	uint32_t quantum;
    uint32_t time;
    uint32_t prev_process;
public:
	RoundRobin(uint32_t quantum = 0);
	~RoundRobin();
	void add_new_process(Process&);
	std::string get_next_event();
	bool is_finished();

    struct CompareArrival {
        bool operator()(Process& p1, Process& p2) {
            return p1.get_arrival_time() != p2.get_arrival_time() ?
                   p1.get_arrival_time() > p2.get_arrival_time() :
                   p1.get_id() > p2.get_id();
        }
    };
private:
    std::priority_queue<Process, std::vector<Process>, CompareArrival> arrival_queue;
};
