#pragma once

#include "Scheduler.hh"

class ShortestJobFirst : public Scheduler {
private:
	bool preemptive;
public:
	ShortestJobFirst(bool preemptive = true);
	~ShortestJobFirst();
	void add_new_process(std::stringstream&);
	std::string make_tick();
	bool is_finished();
    void arrive();
};
