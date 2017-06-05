project(SchedulerEmulator)
add_definitions(-std=c++14)
set(scheduler_src
        Process.cc
        EDF.cc
        LT.cc
        RM.cc
        RR.cc
        SJF.cc
        Scheduler.hh)
add_library(scheduler_lib SHARED ${scheduler_src})
add_executable(scheduler_main main.cc)
target_link_libraries(scheduler_main scheduler_lib)