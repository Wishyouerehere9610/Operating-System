#include "q.h"


void start_thread(void(*function)(void), TCB_t* head)
{
	void *stackP = (void *)malloc(8192);
	if (head->payload != 0)
	{
		TCB_t* tcb = (TCB_t*)malloc(sizeof(TCB_t));
		init_TCB(tcb, function, stackP, 8192);
		tcb->payload = 1;
		addQueue(head, tcb);
	}
	else
	{
		init_TCB(head, function, stackP, 8192);
		head->payload = 1;
	}
	
}
void run(TCB_t* head)
{
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &(head->context));
	
}


void yield(TCB_t* head)
{
	rotateQ(head);
	TCB_t* temp = head;
	temp = temp->next;	
	
	swapcontext(&(head->context), &(temp->context));
	

}

