#pragma once

#include <queue>
#include <string>
#include "process.hh"

class Scheduler {
protected:
	std::priority_queue<Process> queue;
	std::string type;
public:
	Scheduler() { };
	virtual ~Scheduler();
	virtual void add_new_process(Process);
	virtual std::string get_next_event();
	virtual bool is_finished();
	virtual bool compare(Process, Process) = true;
	std::string get_type() { return type; }
};
