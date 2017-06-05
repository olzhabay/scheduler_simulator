#include <netinet/in.h>
#include "LT.hh"

Lottery::Lottery() {

}

Lottery::Lottery(int) {

}

Lottery::~Lottery() {

}

void Lottery::add_new_process(Process) {

}

std::string Lottery::get_next_event() {
    return Scheduler::get_next_event();
}

bool Lottery::is_finished() {
    return Scheduler::is_finished();
}
