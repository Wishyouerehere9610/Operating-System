// Ziming Dong
// CSE 330
// Project 2
// Write test routines that thoroughly test the queue implementation. Use multiple
// queues. Pay special attention to deleting the last element of a q. Also make sure
// “RotateQ” is behaves properly

#ifndef Q_H
#define Q_H

// Include Files //
#include <stdlib.h>
#include <unistd.h>
#include "tcb.h"


// Data Structure Declaration //
typedef struct queue {
    struct TCB_t *header; // Pointer to 1st Element in Queue
} queue;

// Multiple Queues Method  Declaration //
// creates an empty queue, pointed to by the variable head
void initQueue(struct queue*);
// adds a queue item, pointed to by item, to the queue pointed to by head
void addQueue(struct queue*, struct TCB_t*);
// moves the header pointer to the next element in the queue
void rotQueue(struct queue*);
// deletes an item from head
struct TCB_t* delQueue(struct queue*);
// create a new q-element
struct TCB_t* newItem();




// initQueue Method

void initQueue(struct queue *head) {
    // initialize head to Null
    head->header = NULL;

    return;
}


// addQueue Method //
void addQueue(struct queue *head, struct TCB_t *item) {
    // Check for 0 elements in Queue
    if (head->header != NULL) {
        if (head->header->next != NULL) {
            // insert new item to end
            item->prev = head->header->prev; // Add new link at end of chain
            item->next = head->header; // Attach new link to beginning of chain
            head->header->prev->next = item; // Make link from last element
            head->header->prev = item; // Make link to end from head
        } else {
            // Queue has 1 element so create new chain
            head->header->next = item; // Add new link to new item
            head->header->prev = item; // Create chain linking to last element
            item->next = head->header; // Create chain linking to first element
            item->prev = head->header; // Add new link to old item
        }
    } else {
        // Queue is empty
        head->header = item; // head points to first element
        item->prev = NULL;
        item->next = NULL;
    }

    return;
}


// rotQueue Method //
void rotQueue(struct queue *head) {
    // Moves the header pointer to the next element in the queue.
    addQueue(head, delQueue(head));

    return;
}


// delQueue Method //
// deletes an item from head and returns a pointer to the deleted item
struct TCB_t* delQueue(struct queue *head) {
    // Grab the first element in the Queue
    struct TCB_t *item = head->header;

    // Check empty Queue
    if (head->header != NULL) {
        // Check for single or multiple elements in Queue
        if (head->header->next != NULL) {
            // Grab the last element and next element, assign next and prev to recreate chain
            head->header->prev->next = head->header->next;
            head->header->next->prev = head->header->prev;

            // Set the Queue header to next
            head->header = head->header->next;
        } else {
            // Remove single element in the Queue
            head->header = NULL;
        }
    }

    return item;
}


// newItem Method //
// returns a pointer to a new q-element
struct TCB_t* newItem() {
    // Allocate memory for new Queue element
    struct TCB_t *item = (struct TCB_t*) malloc(sizeof(struct TCB_t));

    // Verify  where memory is allocated
    if (!item) {
        item->prev = NULL; // Initialize Previous Element
        item->next = NULL; // Initialize Next Element
    }

    return item;
}
#endif