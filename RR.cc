#include "RR.hh"

RoundRobin::RoundRobin(int quantum) {
    this->quantum = quantum;
    count = 0;
}

RoundRobin::~RoundRobin() {

}

void RoundRobin::add_new_process(Process) {

}

std::string RoundRobin::get_next_event() {
    return Scheduler::get_next_event();
}

bool RoundRobin::is_finished() {
    return Scheduler::is_finished();
}
