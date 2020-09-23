#include <stdio.h>
#include <stdlib.h>

struct process{
    int id, at, bt, ct, tat, wt;
};

//Comparator for burst time with respect to process id
int comparator(const void *p, const void *q)
{
    struct process *pa = (struct process *) p;
    struct process *pb = (struct process *) q;
    int res = pa->bt - pb->bt;
    return res != 0 ? res : pa->id - pb->id;
}
//Comparator for arrival time with respect to process burst time
int comparator0(const void *p, const void *q)
{
    struct process *pa = (struct process *) p;
    struct process *pb = (struct process *) q;
    int res = pa->at - pb->at;
    return res != 0 ? res : pa->bt - pb->bt;
}

int main() {

    // at - arrival time
    // bt - burst time
    // ct - completion time
    // tat - turnaround time
    // wt - waiting time
    
    printf("Enter the number of processes:");
    int n; // number of processes
    scanf("%d", &n);
    
    struct process p[n];
    
    for (int i = 0; i < n; i++){
        printf("AT of process #%d:", i + 1);
        scanf("%d", &p[i].at);
        printf("BT of process #%d:", i + 1);
        scanf("%d", &p[i].bt);
        p[i].id = i + 1;
    }

    //qsort for burst time with respect to process id
    qsort(p, n, sizeof(struct process), comparator);
    //qsort for arrival time with respect to process burst time
    qsort(p, n, sizeof(struct process), comparator0);

    for (int i = 0; i < n; i++){
        p[i].ct = 0;
    }

    p[0].ct = p[0].at + p[0].bt;      // completion time of first process is sum of arrival and burst time of first process

    for (int i = 1; i < n; i++){
        p[i].ct += p[i - 1].ct + p[i].bt;       // completion time of current process is the sum of completion
                                                // time of previous process and burst time of current process
    }

    double total_tat = 0;                  // total turnaround time
    double total_wt = 0;                   // total waiting time

    for (int i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;         // tat = ct - at
        p[i].wt = p[i].tat - p[i].bt;         // wt = tat - bt
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("ID\t AT\t BT\t CT\t TAT\t WT\n");

    for (int i = 0; i < n; i++){
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", p[i].id, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average turnaround time: %f\n", total_tat/n);
    printf("Average waiting time: %f\n", total_wt/n);

    return 0;
}
