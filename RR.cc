#include <sstream>
#include <climits>
#include "RR.hh"

RoundRobin::RoundRobin(uint32_t quantum) {
    this->quantum = quantum;
    time = 0;
}

RoundRobin::~RoundRobin() {
}

void RoundRobin::add_new_process(Process &process) {
    process.set_priority(INT_MAX - process.get_arrival_time());
    queue.push(process);
}

std::string RoundRobin::get_next_event() {
    std::stringstream ss;
    Process process = queue.top();
    queue.pop();
    if (time < process.get_arrival_time()) time = process.get_arrival_time();
    if (process.get_id() != prev_process_id)
        ss << time << ": schedule P" << process.get_id() << "\n";
    if (quantum < process.get_burst_time()) {
        time += quantum;
        process.set_burst_time(process.get_burst_time() - quantum);
        process.set_priority(process.get_priority() - quantum);
        queue.push(process);
        prev_process_id = process.get_id();
    } else {
        time += process.get_burst_time();
        process.set_burst_time(0);
        ss << time << ": terminate P" << process.get_id() << "\n";
    }
    return ss.str();
}

bool RoundRobin::is_finished() {
    return queue.empty();
}
