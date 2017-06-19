#pragma once

#include "Scheduler.hh"

class RoundRobin : public Scheduler {
private:
	uint32_t quantum;
    uint32_t prev_process;
public:
	RoundRobin(uint32_t quantum = 0);
	~RoundRobin();
	void add_new_process(std::stringstream&);
	std::string make_tick();
	bool is_finished();
    void arrive();
};
