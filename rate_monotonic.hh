#pragma once

#include "scheduler.hh"

class RateMonotonic : public Scheduler {
private:
public:
    RateMonotonic();
    ~RateMonotonic();
    void add_new_process(Process);
    std::string get_next_event();
    bool is_finished();
    bool compare(Process, Process);
};
