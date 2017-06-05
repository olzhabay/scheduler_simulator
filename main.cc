#include <iostream>
#include <sstream>
#include <memory>
#include <unistd.h>
#include "scheduler.hh"
#include "shortest_job_first.hh"
#include "round_robin.hh"
#include "rate_monotonic.hh"
#include "earliest_job_first.hh"
#include "lottery.hh"

void print_usage() {
	std::cout << "Usage: command -i [input_file] -s [scheduler_type]\n";
	std::cout << "Optional for RR scheduler: -q [time_quantum]\n";
	std::cout << "Optional for RM and EDF scheduler: -e [simulation_end_time]\n";
}

std::shared_ptr<Scheduler> get_scheduler(std::string type) {
    if (type.compare("SJF")) {
        return std::make_shared<ShortestJobFirst>();
    } else if (type.compare("RR")) {
        return std::make_shared<RoundRobin>();
    } else if (type.compare("RM")) {
        return std::make_shared<RateMonotonic>();
    } else if (type.compare("EDF")) {
        return std::make_shared<EarliestDeadlineFirst>();
    } else if (type.compare("LT")) {
        return std::make_shared<Lottery>();
    } else {
        throw "Wrong argument";
    }
}

int main(int argc, char** argv) {
	std::string input_file;
	std::string type;
	int quantum;
	int end_time;
    int c;
	while ((c = getopt(argc, argv, "i:s:q::e::")) != -1) {
        switch(c) {
            case 'i':
                input_file = optarg;
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
	std::shared_ptr<Scheduler> scheduler = get_scheduler(type);
}
