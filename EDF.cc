#include "EDF.hh"

EarliestDeadlineFirst::EarliestDeadlineFirst(uint32_t end_time) {
    this->end_time = end_time;
    time = 0;
}

EarliestDeadlineFirst::~EarliestDeadlineFirst() {

}

void EarliestDeadlineFirst::add_new_process(std::stringstream &stream) {
    uint32_t id, period, processing_time;
    stream >> id >> period >> processing_time;
    Process process(id, 0, processing_time, period, processing_time);
    arrival_queue.push(process);
}

std::string EarliestDeadlineFirst::get_next_event() {
    std::stringstream ss;
    while (!arrival_queue.empty() && arrival_queue.top().get_arrival_time() == time) {
        Process process = arrival_queue.top();
        arrival_queue.pop();
        process.set_priority(INT16_MAX - time - process.get_period());
        queue.push(process);
    }
    if (queue.empty()) {
        time++;
        return ss.str();
    }
    Process process = queue.top();
    queue.pop();
    if (process.get_arrival_time() + process.get_period() < time) {
        process.set_arrival_time(process.get_period() * (time / process.get_period() + 1));
        process.set_burst_time(process.get_processing_time());
        arrival_queue.push(process);
        return ss.str();
    }
    if (prev_process != process.get_id()) {
        ss << time << ": schedule P" << process.get_id() << "\n";
    }
    prev_process = process.get_id();
    time++;
    process.set_burst_time(process.get_burst_time() - 1);
    if (process.get_burst_time() == 0) {
        process.set_arrival_time(process.get_period() * (time / process.get_period() + 1));
        process.set_burst_time(process.get_processing_time());
        arrival_queue.push(process);
        ss << time << ": terminate P" << process.get_id() << "\n";
    } else {
        queue.push(process);
    }
    return ss.str();
}

bool EarliestDeadlineFirst::is_finished() {
    return time > end_time;
}
