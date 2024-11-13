#include <stdio.h>

int main() 
{
    int r, i;
    printf("Enter total number of processes: ");
    scanf("%d", &r);

    int pid[r], at[r], bt[r], ct[r], tat[r], wt[r];
    
    // Input process details
    for(i=0;i<r;i++) 
    {
        printf("Enter process ID, Arrival time, Burst time for process %d: ", i+1);
        scanf("%d%d%d", &pid[i], &at[i], &bt[i]);
    }

    int completed[r], count=0, time=0;
    // Initialize completed to 0
    for(i=0;i<r;i++) 
    {
        completed[i]=0;
    }
    int gantt_process[r], gantt_end[r], gantt_index=0;

    // Find process with earliest arrival
    int min=0;
    for(i=1;i<r;i++) 
    {
        if(at[i]<at[min]) 
        {   
            min=i;
        }
    }

    // Schedule first process
    ct[min] = at[min] + bt[min];
    tat[min] = ct[min] - at[min];
    wt[min] = tat[min] - bt[min];
    completed[min]=1;
    gantt_process[gantt_index]=pid[min];
    gantt_end[gantt_index++]=ct[min];
    count++;
    time=ct[min];

    // Schedule remaining processes
    while(count<r) 
    {
        int min_bt=9999; // Initialize minimum burst time as a large number
        min = -1;        // Reset the index of the next process to schedule

        // Find the next process with the shortest burst time that has arrived
        for(i=0;i<r;i++) 
        {
            if(at[i]<=time && !completed[i] && bt[i]<min_bt) 
            {
                min_bt=bt[i];
                min=i;
            }
        }

        if(min!=-1) 
        {
        // Schedule the process with the shortest burst time
            ct[min]=time+bt[min];
            tat[min]=ct[min]-at[min];
            wt[min]=tat[min]-bt[min];
            completed[min]=1;
            gantt_process[gantt_index]=pid[min];
            gantt_end[gantt_index++]=ct[min];
            count++;
            time=ct[min];
        } 
        else 
        {
            // Increment time if no process is ready to be scheduled
            time++;
        }
    }

    // Display process details
    printf("P ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<r;i++) printf("%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

    // Display Gantt Chart
    printf("\nGantt Chart:\n");
    for(i=0;i<gantt_index;i++) 
    {
        if(i>0) printf(" -> ");
        printf("P%d", gantt_process[i]);
    }
    // Print the start time of the first process in the Gantt Chart
    printf("\n%d", at[gantt_process[0]-1]);

    // Print completion times for each process in the order they appear in the Gantt Chart
    for(i=0;i<gantt_index;i++) 
    {
        printf("    %d", gantt_end[i]);
    }
    printf("\n");

    return 0;
}
