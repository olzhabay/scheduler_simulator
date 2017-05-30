#pragma once

#include "scheduler.hh"

class Lottery : public Scheduler {
private:
public:
    Lottery();
    ~Lottery();
    void add_new_process(int, int, int);
    std::string get_next_event();
    bool is_finished();
    bool compare(Process, Process);
};
