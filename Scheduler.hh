#pragma once

#include <queue>
#include <string>
#include <functional>
#include "Process.hh"

class Scheduler {
public:
	Scheduler() { };
	virtual ~Scheduler() = default;
	virtual void add_new_process(Process) = 0;
	virtual std::string get_next_event() { };
	virtual bool is_finished() { };
	std::string get_type() { return type; }
    struct Compare {
        bool operator()(Process& p1, Process& p2) {
            return p1.get_priority() < p2.get_priority();
        }
    };
protected:
    std::priority_queue<Process, std::vector<Process>, Compare> queue;
    std::string type;
};
