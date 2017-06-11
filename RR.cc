#include <climits>
#include "RR.hh"

RoundRobin::RoundRobin(uint32_t quantum) {
    this->quantum = quantum;
    time = 0;
}

RoundRobin::~RoundRobin() {
}

void RoundRobin::add_new_process(std::stringstream &stream) {
    uint32_t id, arrival_time, burst_time;
    stream >> id >> arrival_time >> burst_time;
    Process process(id, arrival_time, burst_time);
    arrival_queue.push(process);
}

std::string RoundRobin::get_next_event() {
    std::stringstream ss;
    while (!arrival_queue.empty() && arrival_queue.top().get_arrival_time() <= time) {
        Process process = arrival_queue.top();
        process.set_priority(INT_MAX - process.get_arrival_time());
        arrival_queue.pop();
        queue.push(process);
    }
    if (queue.empty()) {
        time = arrival_queue.top().get_arrival_time();
        return ss.str();
    }
    Process process = queue.top();
    queue.pop();
    if (prev_process != process.get_id())
        ss << time << ": schedule P" << process.get_id() << "\n";
    do {
        prev_process = process.get_id();
        uint32_t comp_time = quantum < process.get_burst_time() ? quantum : process.get_burst_time();
        time += comp_time;
        process.set_burst_time(process.get_burst_time() - comp_time);
        process.set_priority(INT_MAX - time);
        if (process.get_burst_time() == 0) {
            ss << time << ": terminate P" << process.get_id() << "\n";
        } else {
            queue.push(process);
        }
    } while (queue.empty() && arrival_queue.empty() && process.get_burst_time() > 0);
    return ss.str();
}

bool RoundRobin::is_finished() {
    return queue.empty() && arrival_queue.empty();
}
