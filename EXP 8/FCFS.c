#include "./process.h"
#include <stdio.h>
#include <stdlib.h>

/* first come first serve policy */
void FCFS(process PCB[]){
    printf("\narrival time of processes: \n");
    for(i = 0; i < n; i++){
        int arrival;
        scanf("%d", &arrival);
        PCB[i].at = arrival;
    }

    int time = 0;

    qsort(PCB, n, sizeof(struct process), compare_arrival);
    
    for(i = 0; i < n; i++){
        PCB[i].wt = time;
        PCB[i].tat = PCB[i].wt + PCB[i].bt;
        PCB[i].rmt = 0;
        time += PCB[i].bt;
    }
    printf("\nFCFS:\n");
    print_processes_info(PCB);
}

int main(int argc, char const *argv[]){
    printf("number of processes: ");
    scanf("%d", &n);

    process PCB[n];
    total_burst = 0;

    printf("\nEnter Burst Time:\n");
    for(i = 0; i < n; i++){
        int burst;
        scanf("%d", &burst);
        total_burst += burst;
        PCB[i].pid = i;
        PCB[i].wt = 0;
        PCB[i].tat = 0;
        PCB[i].at = 0;
        PCB[i].priority = 0;
        PCB[i].bt = burst;
        PCB[i].rmt = burst;
    }
    
    FCFS(PCB);

    int total_wt = 0, total_tat = 0;
	for (int i = 0 ; i < n ; i++)
	{
		total_wt = total_wt + PCB[i].wt;
		total_tat = total_tat + PCB[i].tat;
	}

    printf("Average waiting time = %f", (float)total_wt / (float)n);
	printf("\nAverage turn around time = %f\n", (float)total_tat / (float)n);

    return 0;
}
