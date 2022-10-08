#include <stdio.h>
#include <stdlib.h>

struct Process {
    int i;
    int arrivalTime;
    int burstTime;
};
typedef struct Process Process;


int comparator(const void * elem1, const void * elem2) {
    Process f = *((Process*)elem1);
    Process s = *((Process*)elem2);
    if (f.arrivalTime > s.arrivalTime) return  1;
    if (f.arrivalTime < s.arrivalTime) return -1;
    return 0;
}

int main(void) {
    int n;
    printf("Count of processes: ");
    scanf("%d", &n);

    Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].i = i;
        printf("Arrival time of process %d: ", i);
        scanf("%d", &processes[i].arrivalTime);
        printf("Burst time of process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        printf("Added!\n");
    }

    qsort(processes, n, sizeof(Process), comparator);

    int waitingSum = 0;
    int tatSum = 0;

    int CTs[n];
    for (int i = 0; i < n; i++) {
        int burstTime = processes[i].burstTime;
        int arrivalTime = processes[i].arrivalTime;
        
        if (i == 0 || processes[i].arrivalTime > CTs[i-1]) 
            CTs[i] = processes[i].arrivalTime + processes[i].burstTime;
        else 
            CTs[i] = CTs[i-1] + processes[i].burstTime;

        int waitingTime = CTs[i] - burstTime - arrivalTime;
        int TAT = waitingTime + burstTime;

        waitingSum += waitingTime;
        tatSum += TAT;

        printf("=== Process [%d] ===\n", processes[i].i);
        printf("Waiting time: %d\n", waitingTime);
        printf("TAT: %d\n", TAT);
        printf("CT: %d\n", CTs[i]);
    }

    printf("=== Metrics ===\n");
    float waitingAvg = (float)waitingSum / n;
    float tatAvg = (float)tatSum / n;

    printf("Average waiting time: %f\n", waitingAvg);
    printf("Average TAT: %f\n", tatAvg);

    return EXIT_SUCCESS;
}