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

std::string RoundRobin::make_tick() {
    std::stringstream ss;
    arrive();
    if (queue.empty()) {
        time++;
        return ss.str();
    }
    Process process = queue.top();
    queue.pop();
    static uint32_t quantum;
    if (prev_process != process.get_id()) {
        quantum = this->quantum;
        ss << time << ": schedule P" << process.get_id() << "\n";
        process.set_priority(MAX_PRIORITY);
    }
    prev_process = process.get_id();
    time++;
    quantum--;
    process.burst_tick();
    if (process.get_burst_time() == 0) {
        ss << time << ": terminate P" << process.get_id() << "\n";
    } else {
        if (quantum == 0) {
            if (queue.empty()) {
                // ensure rescheduling process if queue is empty and other process arriving at the moment
                quantum = this->quantum;
                process.set_priority(MAX_PRIORITY);
            } else {
                process.set_priority(MAX_PRIORITY - time);
            }
        }
        queue.push(process);
    }
    return ss.str();
}

bool RoundRobin::is_finished() {
    return queue.empty() && arrival_queue.empty();
}

void RoundRobin::arrive() {
    while (!arrival_queue.empty() && arrival_queue.top().get_arrival_time() == time) {
        Process process = arrival_queue.top();
        arrival_queue.pop();
        process.set_priority(MAX_PRIORITY - process.get_arrival_time());
        queue.push(process);
    }
}
