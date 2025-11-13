#include <stdio.h>
#include<limits.h>

struct process {
    int pid;
    int burst_time;
    int arrival_time;
    int priority;
    int start_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void Gantt_chart(struct process p[], int n, int completed[]) {
    printf("\nGantt Chart -\n");
    int min;
    for(int i=0; i<n; i++) {
        min = -1;
        for(int j=0; j<n; j++) {
            if(completed[j]) {
                if(min==-1 || p[j].completion_time < p[min].completion_time)
                    min = j;
            }
        }
        printf("P%d\t|", p[min].pid);
        completed[min] = 0;
    }
    printf("\n0\t");
    for(int i=0; i<n; i++) {
        min = -1;
        for(int j=0; j<n; j++) {
            if(!completed[j]) {
                if(min==-1|| p[j].completion_time < p[min].completion_time)
                    min = j;
            }
        }
        printf("%d\t", p[min].completion_time);
        completed[min] = 1;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    int completed[n];
    printf("Enter burst time, arrival time, and priority:\n");
    for (int i = 0; i < n; i++) {
        printf("For process %d: ", i + 1);
        scanf("%d %d %d", &p[i].burst_time, &p[i].arrival_time, &p[i].priority);
        p[i].pid = i + 1;
        completed[i] = 0;
    }

    int current_time = 0, completed_count = 0;
    float total_waiting_time = 0, total_turnaround_time = 0, total_completion_time = 0;

    while (completed_count < n) {
        int idx = -1;
        int highest_priority = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!completed[i] && p[i].arrival_time <= current_time && p[i].priority < highest_priority) {
                highest_priority = p[i].priority;
                idx = i;
            }
        }

        if (idx != -1) {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

            total_waiting_time += p[idx].waiting_time;
            total_turnaround_time += p[idx].turnaround_time;
            total_completion_time += p[idx].completion_time;

            current_time = p[idx].completion_time;
            completed[idx] = 1;
            completed_count++;
        } else {
            // If no process has arrived yet, increment time
            current_time++;
        }
    }

    printf("\nPID\tPriority\tArrival\tBurst\tStart\tCompletion\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].priority, p[i].arrival_time,
               p[i].burst_time, p[i].start_time, p[i].completion_time, p[i].waiting_time, p[i].turnaround_time);
    }

    Gantt_chart(p, n, completed);

    printf("\nAverage waiting time = %.2f\n", total_waiting_time / n);
    printf("Average turnaround time = %.2f\n", total_turnaround_time / n);
    printf("Average completion time = %.2f\n", total_completion_time / n);

    return 0;
}
