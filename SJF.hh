#pragma once

#include "Scheduler.hh"

class ShortestJobFirst : public Scheduler {
private:
	bool preemptive;
    uint32_t time = 0;
    uint32_t prev_process;
public:
	ShortestJobFirst(bool preemptive = true);
	~ShortestJobFirst();
	void add_new_process(std::stringstream&);
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
