#pragma once

#include <queue>
#include <string>
#include "process.hh"

class Scheduler {
protected:
	std::priority_queue<Process> queue;
public:
	Scheduler() { };
	virtual ~Scheduler();
	virtual void add_new_process(int, int, int);
	virtual std::string get_next_event();
	virtual bool is_finished();
	virtual bool compare(Process, Process) = true;
};
