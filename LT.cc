#include "LT.hh"

Lottery::Lottery() {

}

Lottery::Lottery(uint32_t quantum) {
    this->quantum = quantum;
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
}

std::string Lottery::make_tick() {
    return Scheduler::make_tick();
}

bool Lottery::is_finished() {
    return Scheduler::is_finished();
}

void Lottery::arrive() {

}
