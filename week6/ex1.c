#include <stdio.h>

int main() {

    // we assume that all the processes are introduced in order based on the arrival time

    // at - arrival time
    // bt - burst time
    // ct - completion time
    // tat - turnaround time
    // wt - waiting time

    printf("Enter the number of processes:");
    int n; // number of processes
    scanf("%d", &n);
    int at[n], bt[n], ct[n], tat[n], wt[n];
    for (int i = 0; i < n; i++){
        printf("AT of process #%d:", i + 1);
        scanf("%d", &at[i]);
        printf("BT of process #%d:", i + 1);
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n; i++){
        ct[i] = 0;
    }

//    int time = at[0];
    ct[0] = at[0] + bt[0];      // completion time of first process is sum of arrival and burst time of first process

    for (int i = 1; i < n; i++){
//        ct[i] = time + bt[i];
//        time = ct[i];
        ct[i] += ct[i - 1] + bt[i];     // completion time of current process is the sum of completion
                                        // time of previous process and burst time of current process
    }

    double total_tat = 0;                  // total turnaround time
    double total_wt = 0;                   // total waiting time

    for (int i = 0; i < n; i++){
        tat[i] = ct[i] - at[i];         // tat = ct - at
        wt[i] = tat[i] - bt[i];         // wt = tat - bt
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("ID\t AT\t BT\t CT\t TAT\t WT\n");

    for (int i = 0; i < n; i++){
        printf("P%d\t %d\t %d\t %d\t %d\t %d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("Average turnaround time: %f\n", total_tat/n);
    printf("Average waiting time: %f\n", total_wt/n);

    return 0;
}
