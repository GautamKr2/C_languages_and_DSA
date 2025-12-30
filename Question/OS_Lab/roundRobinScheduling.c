#include <stdio.h>

int main() {
    int n, i, time = 0, count = 0, flag = 0;
    int quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival[n], burst[n], remaining[n], completion[n], turnaround[n], waiting[n];
    int visited[n];

    printf("Enter arrival time and burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("For process %d: ", i + 1);
        scanf("%d %d", &arrival[i], &burst[i]);
        remaining[i] = burst[i];
        visited[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    printf("\nGantt Chart -\n");

    int completed = 0;
    int executed[n]; // to track if process added to Gantt chart at least once
    for(i = 0; i < n; i++) executed[i] = 0;

    while(completed < n) {
        flag = 0;
        for(i = 0; i < n; i++) {
            if(arrival[i] <= time && remaining[i] > 0) {
                if(remaining[i] > quantum) {
                    printf("|P%d -> %d - %d ", i+1, time, time+quantum);
                    time += quantum;
                    remaining[i] -= quantum;
                    flag = 1;
                } else {
                    printf("|P%d -> %d - %d ", i+1, time, time+remaining[i]);
                    time += remaining[i];
                    completion[i] = time;
                    remaining[i] = 0;
                    completed++;
                    flag = 1;
                }
                executed[i] = 1;
            }
        }
        if(flag == 0) {
            // If no process is ready just increment time
            time++;
        }
    }
    printf("|\n");

    float tct=0, ttt=0, twt=0;
    // Calculate turnaround time and waiting time
    for(i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
        tct += completion[i];
        ttt += turnaround[i];
        twt += waiting[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i+1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAvg. of completion time: %.2f\n", tct/n);
    printf("Avg. of turn around time: %.2f\n", ttt/n);
    printf("Avg. of waiting time: %.2f\n", twt/n);

    return 0;
}
