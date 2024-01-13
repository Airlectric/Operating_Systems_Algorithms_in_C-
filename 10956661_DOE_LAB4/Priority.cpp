#include<iostream>
#include<algorithm>
using namespace std;

struct Process {
    int processId;
    int burstTime;
    int priority;
};

// Function to find the waiting time for all processes
void findWaitingTime(Process processes[], int n, int wt[])
{
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = processes[i - 1].burstTime + wt[i - 1];
}

// Function to calculate turn around time
void findTurnAroundTime(Process processes[], int n, int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = processes[i].burstTime + wt[i];
}

// ... (previous code)

// Function to calculate average time and display Gantt chart
void findavgTime(Process processes[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    // Find waiting time of all processes
    findWaitingTime(processes, n, wt);

    // Find turn around time for all processes
    findTurnAroundTime(processes, n, wt, tat);

    cout << "Processes\tBurst time\tPriority\tWaiting time\tTurn around time\n";

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << processes[i].processId << "\t\t"
             << processes[i].burstTime << "\t\t" << processes[i].priority << "\t\t" << wt[i] << "\t\t " << tat[i] << endl;
    }

    cout << "Average waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;

    // Display Gantt chart
    cout << "\nGantt Chart:\n";
    cout << "-----------------------------------------------------------------\n";
    cout << "| Process |  Entry Time  |  Exit Time   |\n";
    cout << "-----------------------------------------------------------------\n";

    int entryTime = 0;
    for (int i = 0; i < n; i++)
    {
        cout << "|    P" << processes[i].processId << "    |      " << entryTime << "       |      " << entryTime + processes[i].burstTime << "       |\n";
        entryTime += processes[i].burstTime;
    }

    cout << "-----------------------------------------------------------------\n";
}



// Comparison function to sort processes based on priority
bool comparison(Process a, Process b)
{
    return (a.priority < b.priority);
}

int main()
{
    // Input: number of processes, burst times, and priorities
    const int n = 5; // Set the number of processes to 5
    Process processes[n];

    cout << "Enter burst times and priorities for each process:\n";
    for (int i = 0; i < n; i++)
    {
        processes[i].processId = i + 1;
        cout << "Process " << processes[i].processId << " - Burst Time: ";
        cin >> processes[i].burstTime;
        cout << "               Priority: ";
        cin >> processes[i].priority;
    }

    // Sort processes based on priority (higher priority comes first)
    sort(processes, processes + n, comparison);

    findavgTime(processes, n);

    return 0;
}
