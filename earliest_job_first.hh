#pragma once

#include "scheduler.hh"

class EarliestDeadlineFirst : public Scheduler {
private:
public:
    EarliestDeadlineFirst();
    ~EarliestDeadlineFirst();
    void add_new_process(int, int, int);
    std::string get_next_event();
    bool is_finished();
    bool compare(Process, Process);
};
