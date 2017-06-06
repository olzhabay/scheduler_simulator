#pragma once

#include "Scheduler.hh"

class ShortestJobFirst : public Scheduler {
private:
	bool preemptive;
public:
	ShortestJobFirst(bool preemptive = true);
	~ShortestJobFirst();
	void add_new_process(Process&);
	std::string get_next_event();
	bool is_finished();
};
