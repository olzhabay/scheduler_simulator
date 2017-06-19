#include <iostream>
#include <sstream>
#include <memory>
#include <unistd.h>
#include <fstream>
#include "Scheduler.hh"
#include "SJF.hh"
#include "RR.hh"
#include "RM.hh"
#include "EDF.hh"
#include "LT.hh"

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
    if (!type.compare("SJF")) {
        return std::make_shared<ShortestJobFirst>();
    } else if (!type.compare("RR")) {
        return std::make_shared<RoundRobin>(quantum);
    } else if (!type.compare("RM")) {
        return std::make_shared<RateMonotonic>(end_time);
    } else if (!type.compare("EDF")) {
        return std::make_shared<EarliestDeadlineFirst>(end_time);
    } else if (!type.compare("LT")) {
        return std::make_shared<Lottery>();
    } else {
        throw "Wrong argument for scheduler_type\n";
    }
}

int main(int argc, char** argv) {
	std::string file_name;
	std::string type;
	int quantum = 0;
	int end_time = 0;
    int c;
	while ((c = getopt(argc, argv, "i:s:q:e:")) != -1) {
        switch(c) {
            case 'i':
                file_name = optarg;
                break;
            case 's':
                type = optarg;
                break;
            case 'q':
                if (optarg != nullptr)
                    quantum = std::stoi(optarg);
                break;
            case 'e':
                if (optarg != nullptr)
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
    std::ifstream input;
    input.open(file_name);
    while (!input.eof() && input.good()) {
        std::string line;
        getline(input, line);
        std::stringstream ss(line);
        scheduler->add_new_process(ss);
    }
    while (!scheduler->is_finished()) {
        std::cout << scheduler->make_tick();
    }
    return 0;

}
