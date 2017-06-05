#pragma once

#include "Scheduler.hh"

class RateMonotonic : public Scheduler {
private:
    int end_time;
public:
    RateMonotonic(int end_time = 0);
    ~RateMonotonic();
    void add_new_process(Process);
    std::string get_next_event();
    bool is_finished();
};
