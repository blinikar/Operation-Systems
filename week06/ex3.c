#include <stdio.h>
#include <stdlib.h>

struct Process {
    int i;
    int arrivalTime;
    int burstTime;
    int timeToComplete;

    int waitingTime;
};
typedef struct Process Process;


void shiftQueue(int *q, int n) {
    int firstItem = q[0];
    for (int i = 1; i < n; i++) {
        q[i-1] = q[i];
    }
    q[n-1] = firstItem;
}

int main(void) {
    int n;
    printf("Count of processes: ");
    scanf("%d", &n);

    Process processes[n+1];

    for (int i = 0; i < n; i++) {
        processes[i].i = i;
        printf("Arrival time of process %d: ", i);
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst time of process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        
        processes[i].timeToComplete = processes[i].burstTime;
        processes[i].waitingTime = 0;
        
        printf("Added!\n");
    }

    processes[n].i = n;
    processes[n].arrivalTime = __INT_MAX__;
    processes[n].timeToComplete = __INT_MAX__;

    int waitingSum = 0;
    int tatSum = 0;

    int timeQuantum = 3;
    scanf("%d", &timeQuantum);

    int queue[n];
    int queueN = 0;

    int count = 0;
    int inProgress = -1;
    int execTime = 0;
    for (int t = 0; count < n; t++) {
        int smallest = n;

        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime == t) {
                queue[queueN] = i;
                queueN++;
            }
        }

        if (queueN == 0) continue;

        if (inProgress >= 0 && execTime < timeQuantum) smallest = inProgress;
        else {
            smallest = queue[0];
            inProgress = queue[0];
            execTime = 0;
        }

        processes[smallest].timeToComplete--;
        execTime++;

        if (execTime == timeQuantum) shiftQueue(queue, queueN);

        if (processes[smallest].timeToComplete == 0) {
            count++;
            inProgress = -1;

            shiftQueue(queue, queueN);
            queueN--;

            int CT = t+1;
            int waitingTime = CT - processes[smallest].arrivalTime - processes[smallest].burstTime;
            int TAT = CT - processes[smallest].arrivalTime; 

            waitingSum += waitingTime;
            tatSum += TAT;

            printf("=== Process [%d] ===\n", processes[smallest].i);
            printf("Waiting time: %d\n", waitingTime);
            printf("TAT: %d\n", TAT);
            printf("CT: %d\n", CT);
        }
    }

    printf("=== Metrics ===\n");
    float waitingAvg = (float)waitingSum / n;
    float tatAvg = (float)tatSum / n;

    printf("Average waiting time: %f\n", waitingAvg);
    printf("Average TAT: %f\n", tatAvg);

    return EXIT_SUCCESS;
}