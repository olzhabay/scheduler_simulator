#pragma once

#include "Scheduler.hh"

class EarliestDeadlineFirst : public Scheduler {
private:
    uint32_t end_time;
public:
    EarliestDeadlineFirst(uint32_t end_time = 0);
    ~EarliestDeadlineFirst();
    void add_new_process(Process&);
    std::string get_next_event();
    bool is_finished();
};
