// Ziming Dong
// CSE 330
// Project 2
// The queue items defined in your q.h file has to changed, to be of type TCB_t. The
// TCB_t and an initialization routine are provided in a header file tcb.h. Note that
// TCB_t has previous and next pointers along with an ucontext_t field to store a thread.
/* There is a routine in the tcb.h file called init_TCB, which is used to initialize a TCB
for a new thread. The arguments to init_TCB are:
1. pointer to the function, to be executed
2. pointer to the thread stack
3. size of the stack */

#ifndef INC_330TEST_TCB_H
#define INC_330TEST_TCB_H

// Include Files //
#define _XOPEN_SOURCE
#include <ucontext.h>
#include <stdio.h>
#include <string.h>


// Data Structure Declaration //
typedef struct TCB_t {
    struct TCB_t *next;
    struct TCB_t *prev;
    ucontext_t context;
} TCB_t;


// init_TCB Method //
void init_TCB(TCB_t *tcb, void *function, void *stackP, int stack_size) {
    memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked

    return;
}

#endif
