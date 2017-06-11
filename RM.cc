#include "RM.hh"

RateMonotonic::RateMonotonic(uint32_t end_time) {

}

RateMonotonic::~RateMonotonic() {

}

void RateMonotonic::add_new_process(std::stringstream &stream) {
    uint32_t id, period, processing_time;
    stream >> id >> period >> processing_time;
    Process process(id, 0, processing_time, period, processing_time);

}

std::string RateMonotonic::get_next_event() {
    return std::__cxx11::string();
}

bool RateMonotonic::is_finished() {
    return false;
}
