#include <netinet/in.h>
#include "lottery.hh"

Lottery::Lottery() {

}

Lottery::Lottery(int) {

}

Lottery::~Lottery() {

}

void Lottery::add_new_process(Process) {
    Scheduler::add_new_process( < unnamed >);
}

std::string Lottery::get_next_event() {
    return Scheduler::get_next_event();
}

bool Lottery::is_finished() {
    return Scheduler::is_finished();
}

bool Lottery::compare(Process, Process) {
    return false;
}
