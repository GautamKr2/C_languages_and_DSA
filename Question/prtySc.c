#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct process {
    int pid, at, bt, prty, st, ct, tat, wt;
};

int main() {
    int n, time=0, count=0;
    printf("Enter no of process: ");
    scanf("%d", &n);
    struct process p[n];
    int completed[n];
    printf("Enter arrival time, burst time, priority -\n");
    for(int i=0; i<n; i++) {
        printf("For process %d: ", i+1);
        scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].prty);
        completed[i] = 0;
    }

    int idx, h_pr;
    while(count < n) {
        idx = -1;
        h_pr = INT_MAX;
        for(int i=0; i<n; i++) {
            if(!completed[i] && p[i].at<=time && p[i].prty<h_pr) {
                h_pr = p[i].prty;
                idx = i;
            }
        }
        if(idx != -1) {
            printf("|P%d -> %d - %d ", idx+1, time, time+p[idx].bt);
            p[idx].st = time;
            time += p[idx].bt;
            p[idx].ct = time;
            completed[idx] = 1;
            count++;
        } else printf("|ideal -> %d - %d", time, time++);
    }
    printf("|\n");
    float tct=0, ttt=0, twt=0;
    for(int i=0; i<n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        tct += p[i].ct;
        ttt += p[i].tat;
        twt += p[i].wt;
    }

    printf("\nPId\tAT\tBT\tPrty\tST\tCT\tTaT\tWT\n");
    for(int i=0; i<n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", i+1, p[i].at, p[i].bt, p[i].prty, p[i].st, p[i].ct, p[i].tat, p[i].wt);

    printf("\nAvg. of completion time = %.2f\n", tct/n);
    printf("Avg, of turn around time = %.2f\n", ttt/n);
    printf("Avg. of waiting time = %.2f\n", twt/n);
    return 0;
}