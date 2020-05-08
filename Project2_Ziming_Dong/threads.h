// Ziming Dong
// CSE 330
// Project 2
// Write a routine called start_thread and put it in a file called “threads.h”,
// Write the routines called “yield” and “run” which cranks up the works (and put them in threads.h).

#ifndef INC_330TEST_THREADS_H
#define INC_330TEST_THREADS_H

// Include Files //
#include "q.h"

// Global Variable Declaration //
struct queue *runQ;


// Method Declaration //
void startThread(void (*function)(void));
void run();
void yield();


// start_thread Method //
void startThread(void (*function)(void)) {
    TCB_t *temp = newItem();
    void *stack = (void *) malloc(8192);
    init_TCB(temp, function, stack, 8192);
    addQueue(runQ, temp);

    return;
}
// Write the routines called “yield” and “run” which cranks up the works (and put them in threads.h)

// run Method //
void run() {
    ucontext_t parent;
    getcontext(&parent);
    swapcontext(&parent, &(runQ->header->context));

    return;
}


// yield Method //
void yield() {
    ucontext_t from, to;
    getcontext(&from);
    runQ->header->context = from;
    rotQueue(runQ);
    to = runQ->header->context;
    swapcontext(&from, &to);

    return;
}



#endif
