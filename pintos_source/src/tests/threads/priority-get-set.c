#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/init.h"
#include "devices/timer.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"

void test_priority_get_set(void) {
    // Test scenario 1: Check initial priority & base priority
    ASSERT(thread_get_priority() == PRI_DEFAULT);
    ASSERT(thread_get_base_priority() == PRI_DEFAULT);

    // Test scenario 2: Change priority & ensure base_priority is the original value
    thread_set_priority(10);
    ASSERT(thread_get_priority() == 10);
    ASSERT(thread_get_base_priority() == PRI_DEFAULT);
}
