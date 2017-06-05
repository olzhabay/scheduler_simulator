#pragma once

#include "scheduler.hh"

class Lottery : public Scheduler {
private:
public:
    Lottery();
    Lottery(int);
    ~Lottery();
    void add_new_process(Process);
    std::string get_next_event();
    bool is_finished();
    bool compare(Process, Process);
};
