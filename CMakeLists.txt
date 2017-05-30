project(SchedulerEmulator)

set(scheduler_src
        process.cc
        earliest_job_first.cc
        lottery.cc
        rate_monotonic.cc
        round_robin.cc
        shortest_job_first.cc)
add_library(scheduler_lib SHARED ${scheduler_src})
add_executable(scheduler_main main.cc)
target_link_libraries(scheduler_main scheduler_lib)