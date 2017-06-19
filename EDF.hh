#pragma once

#include "Scheduler.hh"

class EarliestDeadlineFirst : public Scheduler {
private:
    uint32_t end_time;
    uint32_t prev_process;
public:
    EarliestDeadlineFirst(uint32_t end_time = 0);
    ~EarliestDeadlineFirst();
    void add_new_process(std::stringstream&);
    std::string make_tick();
    bool is_finished();
    void arrive();
};
