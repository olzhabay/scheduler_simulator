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
};
