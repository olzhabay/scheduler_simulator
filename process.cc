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
