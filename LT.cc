#include <ctime>
#include <cstdlib>
#include "LT.hh"

Lottery::Lottery(uint32_t quantum, bool random_factor) {
    std::srand(std::time(NULL));
    this->quantum = quantum;
    this->random_factor = random_factor;
    total_ticket_number = 0;
}

Lottery::~Lottery() {

}

void Lottery::add_new_process(std::stringstream &stream) {
    uint32_t id, arrival_time, burst_time, ticket_numbers, resource_type = 0;
    stream >> id >> arrival_time >> burst_time >> ticket_numbers;
    if (!stream.eof()) {
        stream >> resource_type;
    }
    Process process(id, arrival_time, burst_time);
    process.set_ticket_number(ticket_numbers);
    process.set_resource_type(resource_type);
    arrival_queue.push(process);
    total_ticket_number += ticket_numbers;
}

std::string Lottery::make_tick() {
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
            if (random_factor) {
                get_random_ticket(process);
            } else {
                process.set_priority(process.get_ticket_number());
            }
        }
        queue.push(process);
    }
    return ss.str();
}

bool Lottery::is_finished() {
    return queue.empty() && arrival_queue.empty();
}

void Lottery::arrive() {
    while (!arrival_queue.empty() && arrival_queue.top().get_arrival_time() == time) {
        Process process = arrival_queue.top();
        arrival_queue.pop();
        if (random_factor) {
            get_random_ticket(process);
        } else {
            process.set_priority(process.get_ticket_number());
        }
        queue.push(process);
    }
}

void Lottery::get_random_ticket(Process &process) {
    uint32_t priority = MAX_PRIORITY;
    for (int i = 0; i < process.get_ticket_number(); i++) {
        uint32_t r = std::rand() % total_ticket_number;
        priority = r < priority ? r : priority;
    }
    process.set_priority(MAX_PRIORITY - time - priority);
}
