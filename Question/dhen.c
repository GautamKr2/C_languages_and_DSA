/*#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], ct[20], tat[20], wt[20], rbt[20];
    
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rbt[i] = bt[i];   // copy burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, done = 0;

    printf("\nGantt Chart:\n");
    while (done < n) {
        int allIdle = 1;
        for (int i = 0; i < n; i++) {
            if (rbt[i] > 0 && at[i] <= time) {
                allIdle = 0;
                int exec = (rbt[i] > tq) ? tq : rbt[i];
                printf("| P%d (%d-%d) ", i + 1, time, time + exec);
                time += exec;
                rbt[i] -= exec;
                if (rbt[i] == 0) {
                    ct[i] = time;
                    done++;
                }
            }
        }
        if (allIdle) time++; // if CPU idle, move time
    }
    printf("|\n");
    float avg_tat = 0, avg_wt = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turn Around Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}*/



/*#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], ct[20], tat[20], wt[20];

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    // Sort by Arrival Time (FCFS needs arrival order)
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp;
                // swap AT
                temp = at[i]; at[i] = at[j]; at[j] = temp;
                // swap BT
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
            }
        }
    }

    int time = 0;
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        if (time < at[i]) time = at[i]; // CPU idle until arrival
        printf("| P%d (%d-%d) ", i + 1, time, time + bt[i]);
        time += bt[i];
        ct[i] = time;
    }
    printf("|\n");

    float avg_tat = 0, avg_wt = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turn Around Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}*/



/*#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], ct[20], tat[20], wt[20], completed[20], pid[20];
    
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time of P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        completed[i] = 0; // not completed
        pid[i] = i + 1;
    }

    int time = 0, done = 0;
    printf("\nGantt Chart:\n");

    while (done < n) {
        int idx = -1, min_bt = 9999;

        // find process with min BT among arrived and not completed
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if (idx == -1) {
            time++; // CPU idle
            continue;
        }
        printf("| P%d (%d-%d) ", pid[idx], time, time + bt[idx]);
        time += bt[idx];
        ct[idx] = time;
        completed[idx] = 1;
        done++;
    }
    printf("|\n");

    float avg_tat = 0, avg_wt = 0;
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turn Around Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}*/



#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[20], bt[20], pr[20], ct[20], tat[20], wt[20], completed[20], pid[20];
    
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time and Priority of P%d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &pr[i]);
        completed[i] = 0; // not completed yet
        pid[i] = i + 1;
    }

    int time = 0, done = 0;
    printf("\nGantt Chart:\n");

    while (done < n) {
        int idx = -1, best_pr = 9999;

        // pick process with highest priority (lowest number)
        for (int i = 0; i < n; i++) {
            if (!completed[i] && at[i] <= time) {
                if (pr[i] < best_pr) {
                    best_pr = pr[i];
                    idx = i;
                }
                // tie break: same priority → earlier arrival
                else if (pr[i] == best_pr && at[i] < at[idx]) {
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++; // CPU idle
            continue;
        }

        printf("| P%d (%d-%d) ", pid[idx], time, time + bt[idx]);
        time += bt[idx];
        ct[idx] = time;
        completed[idx] = 1;
        done++;
    }
    printf("|\n");

    float avg_tat = 0, avg_wt = 0;
    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turn Around Time = %.2f", avg_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", avg_wt / n);

    return 0;
}