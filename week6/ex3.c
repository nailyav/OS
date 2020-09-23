#include <stdio.h>
#include <stdlib.h>

struct process{
    int id, at, bt, bt0, ct, tat, wt, key;
};

//Comparator for arrival time with respect to process id
int comparator(const void *p, const void *q)
{
    struct process *pa = (struct process *) p;
    struct process *pb = (struct process *) q;
    int res = pa->at - pb->at;
    return res != 0 ? res : pa->id - pb->id;
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
        p[i].bt0 = p[i].bt;                 // reserve burst time
        p[i].id = i + 1;
    }

    printf("Enter the quantum:");
    int q;                                  // quantum
    scanf("%d", &q);

    //qsort for arrival time with respect to process burst time
    qsort(p, n, sizeof(struct process), comparator);

    for (int i = 0; i < n; i++){
        p[i].ct = 0;
        p[i].key = 1;                       // p[i].key is 0 if process # i is done completely (else 1)
    }

    int time = p[0].at;

    int count = 0;                          // counts how many processes have been done completely

    while (count != n){                     // while not all processes are done
        for (int i = 0; i < n; i++){
            if (p[i].key != 0){             // we check if the current process is done or not
                                            // (p[i].key is 0 if process #i is done completely (else 1);)
                if (p[i].bt <= q){          // if bt is less or equal to quantum then find ct as usual
                    count++;                // +1 process is done
                    p[i].key = 0;           // p[i].key is 0 if process #i is done completely (else 1);
                    p[i].ct = time + p[i].bt;
                    time = p[i].ct;
                }
                else if (p[i].bt > q){      // bt is greater than quantum
                    p[i].ct = time + q;     // we add maximum allowed time (that is equal to quantum)
                                            // instead of full burst time
                    time = p[i].ct;
                    p[i].bt -= q;           // subtract quantum from burst time, since part of bt has been already used
                }
            }
        }
    }

    double total_tat = 0;                  // total turnaround time
    double total_wt = 0;                   // total waiting time

    for (int i = 0; i < n; i++){
        p[i].tat = p[i].ct - p[i].at;         // tat = ct - at
        p[i].wt = p[i].tat - p[i].bt0;         // wt = tat - bt
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("ID\t AT\t BT\t CT\t TAT\t WT\n");

    // print p[i].bt0, since p[i].bt is not the same as it was

    for (int i = 0; i < n; i++){
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", p[i].id, p[i].at, p[i].bt0, p[i].ct, p[i].tat, p[i].wt);
    }

    printf("Average turnaround time: %f\n", total_tat/n);
    printf("Average waiting time: %f\n", total_wt/n);

    return 0;
}
