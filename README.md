## Scheduler simulator

### Requirements
C++11/14, cmake

### Compilation

```
cmake .
make
```

### Run

**Example**

```
./scheduler_main -i input.txt -s SJF
```

**Commands**

```
 -i [input_file]
 -s [scheduler_type: RR - Round Robin, SJF - Shortest job first, RM - Rate Monotonic, EDF - Earliest Deadline First, LT - Lottery Scheduler
 -q [time_quantum:  for RR and LT]
 -e [end_time: for RM and EDF]
 -f [no random flag: for LT without random tickets]
 ```
