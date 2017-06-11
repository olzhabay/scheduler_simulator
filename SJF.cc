#include "SJF.hh"

ShortestJobFirst::ShortestJobFirst(bool preemptive) {
    this->preemptive = preemptive;
}

ShortestJobFirst::~ShortestJobFirst() {
}

void ShortestJobFirst::add_new_process(std::stringstream &stream) {
    uint32_t id, arrival_time, burst_time;
    stream >> id >> arrival_time >> burst_time;
    Process process(id, arrival_time, burst_time);
    arrival_queue.push(process);
}

std::string ShortestJobFirst::get_next_event() {
    return std::__cxx11::string();
}

bool ShortestJobFirst::is_finished() {
    return false;
}
