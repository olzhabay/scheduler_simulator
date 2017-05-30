#pragma once

#include "scheduler.hh"

class RoundRobin : public Scheduler {
private:
	int quantum;
public:
	RoundRobin(int quantum = 0);
	~RoundRobin();
	void add_new_process(int, int, int);
	std::string get_next_event();
	bool is_finished();
	bool compare(Process, Process);
};
