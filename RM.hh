#pragma once

#include "Scheduler.hh"

class RateMonotonic : public Scheduler {
private:
    int end_time;
    uint32_t time;
    uint32_t prev_process;
public:
    RateMonotonic(uint32_t end_time = 0);
    ~RateMonotonic();
    void add_new_process(std::stringstream&);
    std::string get_next_event();
    bool is_finished();
};
