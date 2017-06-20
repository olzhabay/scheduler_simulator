#include "SJF.hh"

ShortestJobFirst::ShortestJobFirst(bool preemptive) {
    this->preemptive = preemptive;
    time = 0;
}

ShortestJobFirst::~ShortestJobFirst() {
}

void ShortestJobFirst::add_new_process(std::stringstream &stream) {
    uint32_t id, arrival_time, burst_time;
    stream >> id >> arrival_time >> burst_time;
    Process process(id, arrival_time, burst_time);
    arrival_queue.push(process);
}

std::string ShortestJobFirst::make_tick() {
    std::stringstream ss;
    arrive();
    if (queue.empty()) {
        time++;
        return ss.str();
    }
    Process process = queue.top();
    queue.pop();
    if (prev_process != process.get_id()) {
        ss << time << ": schedule P" << process.get_id() << "\n";
    }
    prev_process = process.get_id();
    time++;
    process.set_burst_time(process.get_burst_time() - 1);
    process.set_priority(process.get_priority() + 1);
    if (process.get_burst_time() == 0) {
        ss << time << ": terminate P" << process.get_id() << "\n";
    } else {
        queue.push(process);
    }
    return ss.str();
}

bool ShortestJobFirst::is_finished() {
    return queue.empty() && arrival_queue.empty();
}

void ShortestJobFirst::arrive() {
    while (!arrival_queue.empty() && arrival_queue.top().get_arrival_time() == time) {
        Process process = arrival_queue.top();
        arrival_queue.pop();
        process.set_priority(MAX_PRIORITY - process.get_burst_time());
        queue.push(process);
    }
}

