#include "scheduler.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Process* create(int priority, int ptime){
        Process* process  = calloc(sizeof(Process),1);
        process->priority = priority;        
        process->ptime = ptime;
        process->next = NULL;
        return process;
};

Scheduler* createScheduler(int sliceTime,Process* process){
     Scheduler* scheduler = calloc(sizeof(Scheduler),1);
     scheduler->sliceTime = sliceTime;
     scheduler->process = process;
     return scheduler;  
};

int insert(Scheduler* scheduler,Process* process){
    Process *temp2,*temp = scheduler->process;
    if(temp == NULL) scheduler->process = process;
    else{
        if(process->priority < temp->priority && temp->next!=NULL){
            temp2 = temp;
            temp = temp->next;
        }
        process->next = temp;
        temp2->next = process;
    }
    scheduler->length++;
    return 1;
}
int schedule(Scheduler* scheduler){
    int i;
    int count = 0;
    Process* process = scheduler->process,*temp;
    for(i = 0; i<scheduler->length;i++){
        if(process->ptime == 0){
            scheduler->length--;
            free(process);
        }
        process->ptime -= scheduler->sliceTime;
        count++;
    }
    return count;
}