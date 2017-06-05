#include "process.hh"

Process::Process(int id, int arrival_time, int burst_time) {
	this->id = id;
	this->arrival_time = arrival_time;
	this->burst_time = burst_time;
}

int Process::get_id() {
	return id;
}

int Process::get_arrival_time() {
	return arrival_time;
}

int Process::get_burst_time() {
	return burst_time;
}

void Process::set_ticket_number(int ticket_number) {
	this->ticket_number = ticket_number;
}

int Process::get_ticket_number() {
    return ticket_number;
}

void Process::set_resource_type(int) {
   this->resource_type = resource_type;
}

int Process::get_resource_type() {
    return resource_type;
}
