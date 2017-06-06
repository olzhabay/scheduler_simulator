#pragma once

#include "Scheduler.hh"

class RoundRobin : public Scheduler {
private:
	uint32_t quantum;
    uint32_t time;
    uint32_t prev_process_id;
public:
	RoundRobin(uint32_t quantum = 0);
	~RoundRobin();
	void add_new_process(Process&);
	std::string get_next_event();
	bool is_finished();
};
