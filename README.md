# PintOs Kernel Hacking Assignment 2(Team #7)

## Overview
We implemented Stanford's Advanced Scheduler (section 2.2.4 of the Operating Systems textbook) for PintOS, specifically a multilevel feedback queue scheduler (MLFQS). This complex feature required deep understanding and modification of PintOS's original Round Robin scheduler.

## Problem Statement
Our task was to address Stanford's PintOS assignment, detailed in section [2.2.4](https://web.stanford.edu/class/cs140/projects/pintos/pintos_2.html#SEC27), and prerequisite priority scheduling described in [2.2.3](https://web.stanford.edu/class/cs140/projects/pintos/pintos_2.html#SEC26).

## Implementation Steps
1. **Maintain Round Robin Scheduler**: Preserved as a fallback mechanism for MLFQS.
2. **Implement Prioritization**: Integrated priority scheduling as a foundation for MLFQS.
3. **Dynamic Priority Calculation**: The heart of MLFQS, involving fixed-point arithmetic and recalculating priorities based on CPU usage and "niceness".

## Data Structures and Algorithms
We updated `threads.h` and `fixed_point.h` to incorporate new fields and arithmetic operations essential for MLFQS. Priority scheduling now includes semaphore prioritization, lock acquisition modifications for priority donation, and condition variable ordering by priority.

## Synchronization
Our implementation ensured atomic operations throughout the priority scheduling process, maintaining system stability. Additionally, the sleeping and waking mechanism of threads and the calculation of MLFQS metrics were carefully synchronized.

## Rationale for Design Choices
The precision of fixed-point arithmetic and the enhanced semaphore and lock mechanisms considerably improve system performance. While the implementation complexity and maintenance overhead increased, the benefits of an advanced scheduling algorithm justified these trade-offs.

## Testing and Debugging
Extensive testing was conducted using Stanford's provided tests, ensuring all functionality met the assignment's rigorous standards. Our debugging efforts led to insights into synchronization primitives and the importance of prioritizing threads correctly during wakeup operations.

## Contribution and Collaboration
Every team member worked on all parts of the project, contributing to the final implementation. This collaborative approach ensured a thorough understanding of the system and the changes we made.

## Acceptance Criteria
Our acceptance of the project was based on passing all tests provided by the Stanford instructors, which verified the correct implementation of the MLFQS.

## Repository Link
[COMP_7035_Kernel_Hacking_A2 Repository](https://github.com/SAMi-Rn/COMP_7035_Kernel_Hacking_A2.git)

# All tests have been passed

<img width="543" alt="Screenshot 2023-11-14 at 12 30 22 AM" src="https://github.com/imnorookie/COMP_7035_Kernel_Hacking_A2/assets/108373193/5d1f4279-10b5-4b14-b096-ba6e75d99ffa">

## Youtube Link
``` sh
https://youtu.be/jip-EQH7RGc?si=MrcTyuzUzQGSTzvD
```

