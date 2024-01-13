#include<iostream>
#include<iomanip>
using namespace std;

// Function to find the waiting time for all processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int rem_bt[n];
    for (int i = 0; i < n; i++)
        rem_bt[i] = bt[i];

    int t = 0; // Current time

    while (1)
    {
        bool done = true;

        for (int i = 0; i < n; i++)
        {
            if (rem_bt[i] > 0)
            {
                done = false;

                if (rem_bt[i] > quantum)
                {
                    // Print entry time in Gantt chart
                    cout << setw(3) << t << " | P" << processes[i] << " ";

                    t += quantum;
                    rem_bt[i] -= quantum;

                    // Print exit time in Gantt chart
                    cout << setw(3) << t << " | ";
                }
                else
                {
                    // Print entry time in Gantt chart
                    cout << setw(3) << t << " | P" << processes[i] << " ";

                    t = t + rem_bt[i];
                    wt[i] = t - bt[i];
                    rem_bt[i] = 0;

                    // Print exit time in Gantt chart
                    cout << setw(3) << t << " | ";
                }
            }
        }

        if (done == true)
            break;
    }
}

// Function to calculate turn around time
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int at[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);

    cout << "\nProcesses\tBurst time\tArrival time\tWaiting time\tTurn around time\n";

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t\t" << at[i] << "\t\t" << wt[i] << "\t\t " << tat[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main()
{
    // Input: number of processes, burst times, arrival times, and quantum
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int processes[n];
    int burst_time[n];
    int arrival_time[n];

    cout << "Enter burst times and arrival times for each process:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i] = i + 1;
        cout << "Process " << processes[i] << " - Burst Time: ";
        cin >> burst_time[i];
        cout << "               Arrival Time: ";
        cin >> arrival_time[i];
    }

    int quantum;
    cout << "Enter the time slice (quantum): ";
    cin >> quantum;

    cout << "\nGantt Chart:\n";
    cout << "--------------------------------\n";

    findavgTime(processes, n, burst_time, arrival_time, quantum);

    return 0;
}
