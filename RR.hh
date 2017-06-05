#pragma once

#include "Scheduler.hh"

class RoundRobin : public Scheduler {
private:
	int quantum;
    int count;
public:
	RoundRobin(int quantum = 0);
	~RoundRobin();
	void add_new_process(Process);
	std::string get_next_event();
	bool is_finished();
};
