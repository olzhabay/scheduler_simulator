#pragma once

#include "Scheduler.hh"

class Lottery : public Scheduler {
private:
    uint32_t quantum;
public:
    Lottery();
    Lottery(uint32_t);
    ~Lottery();
    void add_new_process(std::stringstream&);
    std::string make_tick();
    bool is_finished();
    void arrive();
};
