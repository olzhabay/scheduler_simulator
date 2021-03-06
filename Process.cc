#include <cstdint>
#include "Process.hh"

Process::Process(uint32_t id, uint32_t arrival_time, uint32_t burst_time) {
	this->id = id;
	this->arrival_time = arrival_time;
	this->burst_time = burst_time;
}

Process::Process(uint32_t id, uint32_t arrival_time, uint32_t burst_time, uint32_t period, uint32_t processing_time) {
    this->id = id;
    this->arrival_time = arrival_time;
    this->burst_time = burst_time;
    this->period = period;
    this->processing_time = processing_time;
}

Process::Process(const Process &process) {
    this->id = process.id;
    this->arrival_time = process.arrival_time;
    this->burst_time = process.burst_time;
    this->period = process.period;
    this->processing_time = process.processing_time;
    this->ticket_number = process.ticket_number;
    this->resource_type = process.resource_type;
    this->priority = process.priority;
}

Process &Process::operator=(const Process &process) {
    this->id = process.id;
    this->arrival_time = process.arrival_time;
    this->burst_time = process.burst_time;
    this->period = process.period;
    this->processing_time = process.processing_time;
    this->ticket_number = process.ticket_number;
    this->resource_type = process.resource_type;
    this->priority = process.priority;
    return *this;
}

uint32_t Process::get_id() {
	return id;
}

uint32_t Process::get_arrival_time()const {
	return arrival_time;
}

void Process::set_arrival_time(uint32_t arrival_time) {
    this->arrival_time = arrival_time;
}

uint32_t Process::get_burst_time() {
	return burst_time;
}

void Process::set_burst_time(uint32_t burst_time) {
    this->burst_time = burst_time;
}

void Process::set_ticket_number(uint32_t ticket_number) {
	this->ticket_number = ticket_number;
}

uint32_t Process::get_ticket_number() {
    return ticket_number;
}

void Process::set_resource_type(uint32_t) {
   this->resource_type = resource_type;
}

uint32_t Process::get_resource_type() {
    return resource_type;
}

void Process::set_priority(uint32_t priority) {
    this->priority = priority;
}

uint32_t Process::get_priority()const {
    return priority;
}

uint32_t Process::get_period() {
    return period;
}

uint32_t Process::get_processing_time() {
    return processing_time;
}

void Process::burst_tick() {
    burst_time--;
}
