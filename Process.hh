#pragma once

class Process {
private:
	int id;
	int arrival_time;
	int burst_time;
	int ticket_number = 0;
	int resource_type = 0;
    int priority;
public:
	Process(int, int, int);
	~Process() { }
    int get_id();
    int get_arrival_time();
    int get_burst_time();
    void set_ticket_number(int);
    int get_ticket_number();
    void set_resource_type(int);
    int get_resource_type();
    void set_priority(int);
    int get_priority();
};
