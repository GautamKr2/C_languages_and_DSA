#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int pid, at, bt, ct, tt, wt, rt;
} Process;

int main() {
    int n, time=0, count=0;
    printf("Enter no of process: ");
    scanf("%d", &n);
    Process p[n];
    int completed[n];
    printf("Enter arrival time, and burst time -\n");
    for(int i=0; i<n; i++) {
        printf("For process %d: ", i+1);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].pid = i+1;
        p[i].rt = p[i].bt;
        completed[i] = 0;
    }
    printf("Gantt Chart -\n");
    while(count < n) {
        int i, min = -1, hst_rt = INT_MAX;
        for(i=0; i<n; i++) {
            if(!completed[i] && p[i].at<=time && p[i].rt>0) {
                if(p[i].rt < hst_rt) {
                    min = i;
                    hst_rt = p[i].rt;
                }
            }
        }
        if(min == -1) // No any process is ready to execute
            printf(" |Idle -> %d-%d", time++, time);
        else {
            if(p[min].rt > 1) {
                time++;
                p[min].rt--;
            }
            else {
                p[min].rt--;
                completed[min] = 1;
                count++;
                p[min].ct = ++time;
            }
            printf(" |P%d -> %d-%d", p[min].pid, time-1, time);
        }
    }
    float act=0, att=0, awt=0;
    for(int i=0; i<n; i++) {
        p[i].tt = p[i].ct - p[i].at;
        p[i].wt = p[i].tt - p[i].bt;
        act += p[i].ct;
        att += p[i].tt;
        awt += p[i].wt;
    }
    printf("\nPId \tAT \tBT \tCT \tTaT \tWT\n");
    for(int i=0; i<n; i++) {
        printf("P%d \t%d \t%d \t%d \t%d \t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }
    printf("Average completion time = %.2f\n", act/n);
    printf("Average turn around time = %.2f\n", att/n);
    printf("Average waiting time = %.2f\n", awt/n);
    return 0;
}