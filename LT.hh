#pragma once

#include "Scheduler.hh"

class Lottery : public Scheduler {
private:
    uint32_t quantum;
    uint32_t total_ticket_number;
    bool random_factor;
public:
    Lottery(uint32_t quantum = 0, bool random_factor = true);
    ~Lottery();
    void add_new_process(std::stringstream&);
    std::string make_tick();
    bool is_finished();
    void arrive();
    void get_random_ticket(Process&);
};
