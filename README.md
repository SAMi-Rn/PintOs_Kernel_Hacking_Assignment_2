# PintOs Kernel Hacking Assignment 2(Team #7)

## Overview
This project is an integral component of COMP_7035_OS_Assignment2, in which we have successfully implemented the multilevel feedback queue scheduler (MLFQS), as described in Stanford's PintOS specifications, section 2.2.4. We aimed to integrate an advanced process scheduling system into the Pintos Operating System. The goal was to transition from a simplistic round-robin scheduler to a more sophisticated scheduler that dynamically adjusts thread priorities, efficiently distributes processor time, and prevents priority inversion. This endeavour necessitated an in-depth analysis of the existing PintOS codebase and a thorough understanding of complex scheduling algorithms as detailed in Stanford's literature and the original BSD Unix system. The outcome is a Pintos system that is more equitable, efficient, and capable of handling diverse processing tasks with agility and fairness.

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
