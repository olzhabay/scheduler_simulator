#include <iostream>
#include <sstream>
#include <memory>
#include <unistd.h>
#include <fstream>
#include "scheduler.hh"
#include "shortest_job_first.hh"
#include "round_robin.hh"
#include "rate_monotonic.hh"
#include "earliest_job_first.hh"
#include "lottery.hh"

void print_usage() {
	std::cout << "Usage: command -i [input_file] -s [scheduler_type]\n"
              << "Optional for RR scheduler: -q [time_quantum]\n"
              << "Optional for RM and EDF scheduler: -e [simulation_end_time]\n"
              << "Scheduler types:\n"
              << "SJF : Shortest Job First\n"
              << "RM : Rate Monotonic\n"
              << "RR : Round Robin\n"
              << "EDF : Earliest Deadline First\n"
              << "LT : Lottery Scheduler\n";
}

std::shared_ptr<Scheduler> get_scheduler(std::string type, int quantum, int end_time) {
    if (type.compare("SJF")) {
        return std::make_shared<ShortestJobFirst>();
    } else if (type.compare("RR")) {
        return std::make_shared<RoundRobin>(quantum);
    } else if (type.compare("RM")) {
        return std::make_shared<RateMonotonic>(end_time);
    } else if (type.compare("EDF")) {
        return std::make_shared<EarliestDeadlineFirst>(end_time);
    } else if (type.compare("LT")) {
        return std::make_shared<Lottery>();
    } else {
        throw "Wrong argument for scheduler_type\n";
    }
}

int main(int argc, char** argv) {
	std::string file_name;
	std::string type;
	int quantum;
	int end_time;
    int c;
	while ((c = getopt(argc, argv, "i:s:q::e::")) != -1) {
        switch(c) {
            case 'i':
                file_name = optarg;
                break;
            case 's':
                type = optarg;
                break;
            case 'q':
                quantum = std::stoi(optarg);
                break;
            case 'e':
                end_time = std::stoi(optarg);
                break;
            case '?':
            default:
                print_usage();
                return 1;
        }
    }
    std::shared_ptr<Scheduler> scheduler;
    try {
        scheduler = get_scheduler(type, quantum, end_time);
    } catch (char* exception) {
        std::cout << exception;
        print_usage();
        return 1;
    }
    std::ifstream input(file_name);
    while (!input.eof()) {
        char* line;
        input.getline(line, 255);
        std::stringstream ss(line);
        int id, arrival_time, burst_time;
        ss >> id >> arrival_time >> burst_time;
        Process process(id, arrival_time, burst_time);
        if (scheduler->get_type().compare("LT")) {
            int ticket_number, resource_type;
            ss >> ticket_number;
            process.set_ticket_number(ticket_number);
            if (!ss.eof()) {
                ss >> resource_type;
                process.set_resource_type(resource_type);
            }
        }
        scheduler->add_new_process(process);
    }

    while (!scheduler->is_finished()) {
        std::cout << scheduler->get_next_event();
    }


}
