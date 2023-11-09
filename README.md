# COMP_7035_Kernel_Hacking_A2 (Team #7)
Implementation of Stanford's 2.2.4* Advanced Scheduler for PintOS — a multilevel feedback queue scheduler (MLFQS).

*-We reference and hyperlink sections of the [Threads chapter of Stanford's Operating Systems](https://web.stanford.edu/class/cs140/projects/pintos/pintos_2.html) digital textbook, as 2.X.X.

We will also reference the "BSD" book where this MLFQS implementation was first proposed (found as an appendix in the above Stanford page). I split that textbook into a PDF with _just_ the **process scheduler** section that we need.

# TODO (rough notes on how to start)
In order to do this assignment, we need to implement priority scheduling sans priority donation (seems to suggest priority inversion is not a problem for MLFQS) as described in [2.2.3](https://web.stanford.edu/class/cs140/projects/pintos/pintos_2.html#SEC26) before we can start on [2.2.4](https://web.stanford.edu/class/cs140/projects/pintos/pintos_2.html#SEC27) — the actual assignment. 

## PRECONDITION: Maintain Round Robin Scheduler
The current scheduler in PintOS is Round Robin, this is good as it is required for MLFQS in the case of multiple threads having the highest priority number. Below is how the process of Round Robinning happens in a fresh clone of PintOS' source:

1. thread_tick() -- line 131, thread.c -- calls inter_yield_on_turn() every time our time quantum happens.
    - NOTE: by default (declared in timer.h) there are 100 OS ticks per second. Can lower the number of ticks for debugging purposes. Default TIME_SLICE is 4 ticks aka every 2.4s.
2. intr_yield_on_return() flags the scheduler to call thread_yield() as soon as the tick_interrupt handler returns execution.
3. thread_yield() -- line 310, thread.c -- grabs the current thread's status to READY and moves it to the end of the queue before calling schedule().

I highlight this flow-of-control to show the default thread scheduling as we have to modify it. For example, we will have to change thread_yield() such that it properly appends threads to the end of its respective queue (i.e. correct priority) in our MLFQS implementation. This will be qualified further below.

## STEP 1: Implement Prioritization
PintOS has a flat Round Robin scheduler as shown above. We need to implement prioritization for 64 priorities (by default, determined by PRI_MIN, PRI_MAX variables in lines 23-25 of thread.h). NOTE: in PintOS, the higher the priority number for the thread, the higher its priority aka 0 is the lowest possible priority a thread can have. General steps to implement this:

1. Change ready_list -- line 25, thread.c -- to either be a PRI_MAX sized array of lists or try some [priority queue](https://en.wikipedia.org/wiki/Priority_queue) implementation.
2. Change every instance of ready_list being usedin the code such that properly pops and appends threads, to the right queue(s), with the right priorities.
3. Use above Round Robining to resolve the issue of choosing which thread to schedule from many threads of the same priority.

## STEP 2: MFQS (likely will be broken up into more steps)

## STEP N. Post-A2
Sometime around when we hand in this assignment, we need to meet and come up with potential ideas for A3. Semester is really busy, but hopefully we'll be able to do something cool. He said no file system stuff. I will try to come up with some rudimentary ideas in the interim.


# Problem Statement
Stanford's PintOS assignment: [2.2.4](https://web.stanford.edu/class/cs140/projects/pintos/pintos_2.html#SEC27)

# Acceptance Criteria
