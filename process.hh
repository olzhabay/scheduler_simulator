#pragma once

class process {
private:
	int id;
	int arrival_time;
	int burst_time;
	int completion_time;
	int ticket_number = 0;
public:
	process(int, int, int);
	~process() { }
	int get_id();
	int get_arrival_time();
	int get_burst_time();
};