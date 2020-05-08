// Ziming Dong
// CSE 330
// Project 2
/* Write a driver program in a file called thread_test.c. Into thread_test.c.c include
threads.h which includes q.h, which includes TCB.h, which includes ucontext.h.
Declare a global RunQ.
    Write a three functions with infinite loops (put a yield in each loop). There should
be one global variable. Each function will have a local variable. The first function
will increment the global variable by 1 and the local variable by 1. The second
function should increment the global variable by 2 and local variable by 1. The third
function will increment the global variable by 3 and the local variable by 1. Each
function should print the following before yielding */

#include "threads.h"

// Global Variables //
int global = 0;

// f1 Method //
void f1(void) {
    // initial local variable =0
    int local = 0;
    // f1 function should print the following before yielding
    for (;;) {
        printf("This is function %d th execution of function f1 with global variable value %d\n", local, global);
        global=global+1;
        local=local+1;
        sleep(1);
        yield();
    }

    return;
}


// f2 Method //
void f2(void) {
    // initial local variable =0
    int local = 0;
    // f2 function should print the following before yielding
    for(;;){
        printf("This is function %d th execution of function f2 with global variable value %d\n", local, global);
        global=global+2;
        local=local+1;
        sleep(1);
        yield();
    }

    return;
}


// f3 Method //
void f3(void) {
    // initial local variable =0
    int local = 0;
    // f3 function should print the following before yielding
    for (;;) {
        printf("This is function %d th execution of function f3 with global variable value %d\n", local, global);
        global=global+3;
        local=local+1;
        sleep(1);
        yield();
    }

    return;
}


// main Method //
int main() {
    runQ = (struct queue*) malloc(sizeof(struct queue));

    initQueue(runQ);
    startThread(f1);
    startThread(f2);
    startThread(f3);
    run();

    return 0;
}
