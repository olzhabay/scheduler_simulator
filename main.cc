#include <iostream>
#include <sstream>

void print_usage() {
	std::cout << "Usage: command -i [input_file] -s [scheduler_type]\n";
	std::cout << "Optional for RR scheduler: -q [time_quantum]\n";
	std::cout << "Optional for RM and EDF scheduler: -e [simulation_end_time]\n";
}

int main(int argc, char* argv) {
	std::string file_name;
	std::string type;
	int quantum;
	int end_time;
	if (argc < 5) {
		print_usage();
	}
	std::stringstream ss(argv);
	while (!ss.eof()) {
		string arg;
		ss >> arg;
		if (arg.compare("-i")) {
			ss >> file_name;
		}
		if (arg.compare("-s")) {
			ss >> type;
		}
		if (arg.compare("-q")) {
			ss >> quantum;
		}
		if (arg.compare("-e")) {
			ss >> end_time;
		}
	}
	Scheduler scheduler;
	switch (type) {
		case "SJF":
			break;
		case "RR":
			break;
		case "RM":
			break;
		case "EDF":
			break;
		case "LT":
			break;
	}
}
