typedef struct {
        int priority;
        int ptime;
        void* next;
}Process;

typedef struct {
        int length;
        int sliceTime;
        Process* process;
}Scheduler;

int schedule(Scheduler* scheduler);
int insert(Scheduler* scheduler,Process* process);
Process* create(int priority, int ptime);
Scheduler* createScheduler(int sliceTime,Process* process);
