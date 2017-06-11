#pragma once

class Process {
private:
	uint32_t id;
	uint32_t arrival_time;
	uint32_t burst_time;
    uint32_t period = 0;
    uint32_t processing_time = 0;
	uint32_t ticket_number = 0;
	uint32_t resource_type = 0;
    uint32_t priority = 0;
public:
    Process() {}
	Process(uint32_t , uint32_t , uint32_t);
    Process(uint32_t , uint32_t , uint32_t , uint32_t , uint32_t);
    Process(const Process&);
    Process& operator=(const Process&);
	~Process() { }
    uint32_t get_id();
    uint32_t get_arrival_time()const;
    void set_arrival_time(uint32_t);
    uint32_t get_burst_time();
    void set_burst_time(uint32_t);
    uint32_t get_ticket_number();
    void set_ticket_number(uint32_t);
    uint32_t get_resource_type();
    void set_resource_type(uint32_t);
    void set_priority(uint32_t);
    uint32_t get_priority()const;
    uint32_t get_period();
    uint32_t get_processing_time();
};
