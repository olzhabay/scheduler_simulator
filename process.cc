#include "process.hh"

process::process(int id, int arrival_time, int burst_time) {
	this.id = id;
	this.arrival_time = arrival_time;
	this.burst_time = burst_time;
}

int process::get_id() {
	return id;
}

int process::get_arrival_time() {
	return arrival_time;
}

int process::get_burst_time() {
	return burst_time;
}
