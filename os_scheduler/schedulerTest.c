#include "testUtils.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "scheduler.h"

void test_for_creating_process(){
    Process* process= create(5,10);
    ASSERT(5==process->priority);
    ASSERT(10==process->ptime);
    ASSERT(NULL==process->next);
};
void test_for_creating_Scheduler(){
    Scheduler* scheduler= createScheduler(5,NULL);
    ASSERT(5==scheduler->sliceTime);
    ASSERT(0==scheduler->length);
    ASSERT(NULL==scheduler->process);
};
void test_for_inserting_process_in_given_empty_scheduler(){
    Process* process= create(5,10);
    Scheduler* scheduler = createScheduler(5,NULL);
    ASSERT(insert(scheduler,process));
    ASSERT(1==scheduler->length);
    ASSERT(5==scheduler->sliceTime);
    ASSERT(process==scheduler->process);
};
void test_for_inserting_processes_in_given_scheduler(){
    Process* process1= create(5,10);
    Process* process2= create(7,10);
    Scheduler* scheduler = createScheduler(5,NULL);
    ASSERT(insert(scheduler,process1));
    ASSERT(insert(scheduler,process2));
    ASSERT(2==scheduler->length);
    ASSERT(5==scheduler->sliceTime);
    
};
void test_insert_process_will_insert_process_in_given_scheduler2(){
    Process* process1= create(5,10);
    Process* process2= create(9,10);
    Process* process3= create(7,10);
    Scheduler* scheduler = createScheduler(5,NULL);
    ASSERT(insert(scheduler,process1));
    ASSERT(insert(scheduler,process2));
    ASSERT(insert(scheduler,process3));
    
};
void test_for_scheduling_the_processes(){
    Process* process1= create(1,300);
    Process* process2= create(3,500);
    Process* process3= create(4,200);
    Scheduler* scheduler = createScheduler(100,NULL);
    ASSERT(insert(scheduler,process1));
    ASSERT(insert(scheduler,process2));
    ASSERT(insert(scheduler,process3));
    ASSERT(3 == schedule(scheduler));
};
