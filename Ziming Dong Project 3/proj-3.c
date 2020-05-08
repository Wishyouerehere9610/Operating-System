//
// Created by Ziming Dong on 2019/11/10.


//Ziming Dong
//CSE 330
//Project 3


#include "threads.h"
TCB_t head;
TCB_t Full;
TCB_t Empty;

int Buffer[6] = {0,0,0,0,0,0};
int ProdNum[6] = {0,0,0,0,0,0};
int semFull = 0;
int semEmpty = 6;
int N=6;
int in=0;
int out=0;
int firstExec=0;
int globalVar=0;
int pVal=0;

void threadDummy(void) {
    
	while(1){	
		if (firstExec == 0) {
			firstExec =1;
		}else{
        		head = *head.next;
    		}

    	printf("\n This is a Dummy thread \n");
    	yield(&head);
   }
}


void P(TCB_t *waitQ, int num, int pc) {
    if (pc) {
        if (semEmpty == 0) {
            TCB_t *delItem = DelQueue(&head);
            head = *head.next;
            addQueue(waitQ, delItem);
            ucontext_t parent;
            getcontext(&parent);
            printf("\n Producer %d is waiting \n", num);
	    pVal = 1;	
            swapcontext(&parent, &(head.context));

        } else if (semEmpty > 0) {
            semEmpty--;
        }


    } else {
        if (semFull == 0) {
            TCB_t *delItem = DelQueue(&head);
            head = *head.next;
            addQueue(waitQ, delItem);
            ucontext_t parent;
            getcontext(&parent);
            printf("\n Consumer %d is waiting \n", num);
	    pVal=1;
            swapcontext(&parent, &(head.context));

        } else if (semFull > 0) {
            	  semFull--;

        }
    }
}

void V(TCB_t *waitQ, int pc){
    if(pc){
         semEmpty++;
	if(waitQ->next == NULL){

	}else{
        	if(waitQ->payload == 0){
			rotateQ(waitQ);
			waitQ = waitQ->next;
		}

		TCB_t *delItem = DelQueue(waitQ);
		if(waitQ->next == NULL/Users/dongziming/Desktop/reader and writer/Screen Shot 2019-11-21 at 3.42.40 PM.png){
		}else{
                	waitQ = waitQ->next;
		}
		addQueue(&head,delItem);
        }
    }else{
	semFull++;
        if(waitQ->next == NULL){
            
        }else{
		if(waitQ->payload == 0){
			rotateQ(waitQ);
			waitQ = waitQ->next;
		}
           
            	TCB_t *delItem = DelQueue(waitQ);
           	if(waitQ->next == NULL){

            	}else{
                	waitQ=waitQ->next;
            	}
            	addQueue(&head,delItem);
        }
    }
}

void Producer1(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,1,1);
        	Buffer[in] = item;
        	ProdNum[in] = 1;
        	in = (in+1)%N;
        	printf("\n Producer 1 is producing item number %d \n", item);
        	V(&Full,0);
		/*
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){

		}else{
		     Full = *Full.next;
		}*/
  
        	yield(&head);

    }
  }



void Producer2(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,2,1);
        	Buffer[in] = item;
        	ProdNum[in] = 2;
        	in = (in+1)%N;
        	printf("\n Producer 2 is producing item number %d \n", item);
        	V(&Full,0);
                /*
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){

		}else{
		     Full = *Full.next;
		}*/
		
        	yield(&head);

    }
  }


void Producer3(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,3,1);
        	Buffer[in] = item;
        	ProdNum[in] = 3;
        	in = (in+1)%N;
        	printf("\n Producer 3 is producing item number %d \n", item);
        	V(&Full,0);
	/*
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  */
        	yield(&head);

    }
  }


void Producer4(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,4,1);
        	Buffer[in] = item;
        	ProdNum[in] = 4;
        	in = (in+1)%N;
        	printf("\n Producer 4 is producing item number %d \n", item);
        	V(&Full,0);
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  
        	yield(&head);

    }
  }



void Producer5(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,5,1);
        	Buffer[in] = item;
        	ProdNum[in] = 5;
        	in = (in+1)%N;
        	printf("\n Producer 5 is producing item number %d \n", item);
        	V(&Full,0);
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  
        	yield(&head);

    }
  }


void Producer6(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,6,1);
        	Buffer[in] = item;
        	ProdNum[in] = 6;
        	in = (in+1)%N;
        	printf("\n Producer 6 is producing item number %d \n", item);
        	V(&Full,0);
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  
        	yield(&head);

    }
  }


void Producer7(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,7,1);
        	Buffer[in] = item;
        	ProdNum[in] = 7;
        	in = (in+1)%N;
        	printf("\n Producer 7 is producing item number %d \n", item);
        	V(&Full,0);
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  
        	yield(&head);

    }
  }


void Producer8(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,8,1);
        	Buffer[in] = item;
        	ProdNum[in] = 8;
        	in = (in+1)%N;
        	printf("\n Producer 8 is producing item number %d \n", item);
        	V(&Full,0);

		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  
        	yield(&head);

    }
  }


void Producer9(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,9,1);
        	Buffer[in] = item;
        	ProdNum[in] = 9;
        	in = (in+1)%N;
        	printf("\n Producer 9 is producing item number %d \n", item);
        	V(&Full,0);
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  
        	yield(&head);

    }
  
}

void Producer10(void) {
    int item = 0;
    while (1) {
		if(pVal){
			pVal=0;
		}else{
        		head = *head.next;
        	}
		item++;
        	P(&Empty,10,1);
        	Buffer[in] = item;
        	ProdNum[in] = 10;
        	in = (in+1)%N;
        	printf("\n Producer 10 is producing item number %d \n", item);
        	V(&Full,0);
		if(Full.payload == 0){
		     Full = *Full.next;
		}
		if(Full.next == NULL){
		}else{
		     Full = *Full.next;
		}
  
        	yield(&head);

    }
  }







void Consumer1(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0; 
		}else{
			head=*head.next;
		}
       
        	P(&Full,1,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 1 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
		
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}
        	yield(&head);
    }
}

void Consumer2(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,2,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 2 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
		
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}
        	yield(&head);
    }
}



void Consumer3(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,3,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 3 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
		
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}
        	
        	yield(&head);
    }
}


void Consumer4(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,4,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 4 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
		/*if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}
        	*/
        	yield(&head);
    }
}

void Consumer5(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,5,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 5 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}
        	
        	yield(&head);
    }
}

void Consumer6(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,6,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 6 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}
        	
        	yield(&head);
    }
}


void Consumer7(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,7,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 7 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
/*
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}*/
        	
        	yield(&head);
    }
}


void Consumer8(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,8,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 8 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
/*
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}*/
        	
        	yield(&head);
    }
}

void Consumer9(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,9,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 9 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
/*
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}
        	*/
        	yield(&head);
    }
}

void Consumer10(void){
    int item;
    int ProdID;
    while(1){
		if(pVal){
			pVal=0;
		}else{
			head=*head.next;
		}
       
        	P(&Full,10,0);
        	item=Buffer[out];
        	ProdID=ProdNum[out];
        	Buffer[out] = 0;
        	ProdNum[out]=0;
        	out=(out+1)%N;
        	printf("\n Consumer 10 is consuming item generated by Producer %d \n", ProdID);
        	V(&Empty,1);
/*
		if(Empty.payload == 0){
		     Empty = *Empty.next;
		}
		if(Empty.next == NULL){
		}else{
		     Empty = *Empty.next;
		}*/
        	
        	yield(&head);
    }
}




int main(){
    InitQueue(&head);
    InitQueue(&Full);	
    InitQueue(&Empty);
    printf("\n Done with the initialization\n");
    start_thread(&threadDummy, &head);
    start_thread(&Consumer1, &head);
    start_thread(&Consumer2, &head);
    start_thread(&Consumer3, &head);
    start_thread(&Producer1, &head);
    start_thread(&Producer2, &head);
    start_thread(&Producer3, &head);
    start_thread(&Producer4, &head);
    start_thread(&Producer5, &head);
    start_thread(&Producer6, &head);
    start_thread(&Producer7, &head);
    start_thread(&Consumer4, &head);
    start_thread(&Consumer5, &head);
    start_thread(&Consumer6, &head);
    start_thread(&Consumer7, &head);
    start_thread(&Consumer8, &head);
    start_thread(&Consumer9, &head);
    start_thread(&Consumer10, &head);
    start_thread(&Producer8, &head);
    start_thread(&Producer9, &head);
    start_thread(&Producer10, &head);
    //start_thread(&thread2, &head);

    printQueue(&head);
    run(&head);
    return(0);

}
