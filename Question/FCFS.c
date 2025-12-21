#include<stdio.h>
#include<stdlib.h>

typedef struct Process {
    int pId, AT, BT, CT, TaT, WT;
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
        scanf("%d %d", &p[i].AT, &p[i].BT);
        p[i].pId = i+1;
        completed[i] = 0;
    }
    for(int i=n-1; i>0; i--) {
        for(int j=0; j<i; j++) {
            if(p[j].AT > p[j+1].AT) {
                Process t = p[j];
                p[j] = p[j+1];
                p[j+1] = t;
            }
        }
    }
    printf("\nGantt chart -\n");
    while(count < n) {
        int idx = -1;
        for(int i=0; i<n; i++) {
            if(!completed[i] && p[i].AT<=time) {
                idx = i;
                break;
            }
        }
        if(idx!=-1) {
            printf("| P%d -> %d - %d ", p[idx].pId, time, time+p[idx].BT);
            p[idx].CT = time + p[idx].BT;
            time += p[idx].BT;
            p[idx].TaT = p[idx].CT - p[idx].AT;
            p[idx].WT = p[idx].TaT - p[idx].BT;
            completed[idx] = 1;
            count++;
        }
        else time++;
    }

    printf("\nPId\t AT\t BT\t CT\t TaT\t WT\n");
    for(int i=0; i<n; i++) {
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", p[i].pId, p[i].AT, p[i].BT, p[i].CT, p[i].TaT, p[i].WT);
    }

    float tCT=0, tTT=0, tWT=0;
    for(int i=0; i<n; i++) {
        tCT += p[i].CT;
        tTT += p[i].TaT;
        tWT += p[i].WT;
    }
    printf("|Average Completion time = %.2f\n", tCT/n);
    printf("Average Turnaround time = %.2f\n", tTT/n);
    printf("Average waiting time = %.2f\n", tWT/n);

    return 0;
}