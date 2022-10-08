#include <stdio.h>
#include <stdlib.h>

struct Process {
    int i;
    int arrivalTime;
    int burstTime;
    int timeToComplete;
};
typedef struct Process Process;


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
        
        printf("Added!\n");
    }

    processes[n].i = n;
    processes[n].arrivalTime = 0;
    processes[n].timeToComplete = __INT_MAX__;

    int waitingSum = 0;
    int tatSum = 0;

    int count = 0;
    int inProgress = -1;
    for (int t = 0; count < n; t++) {
        int smallest = n;

        if (inProgress >= 0) smallest = inProgress;
        else for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= t 
                    && processes[i].timeToComplete < processes[smallest].timeToComplete
                    && processes[i].timeToComplete > 0) {
                smallest = i;
                inProgress = i;
            }
        }

        processes[smallest].timeToComplete--;

        if (processes[smallest].timeToComplete == 0) {
            count++;
            inProgress = -1;

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
    float waitingAvg = waitingSum / n;
    float tatAvg = tatSum / n;

    printf("Average waiting time: %f\n", waitingAvg);
    printf("Average TAT: %f\n", tatAvg);

    return EXIT_SUCCESS;
}