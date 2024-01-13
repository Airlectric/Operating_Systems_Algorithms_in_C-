#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct Process {
    int pid;         // Process ID
    int bt;          // Burst Time
    int art;         // Arrival Time
    int entryTime;   // Entry Time in Gantt Chart
    int exitTime;    // Exit Time in Gantt Chart
};

void findWaitingTime(vector<Process> &proc, int n, int wt[], vector<int> &schedulingOrder) {
    int rt[n];

    for (int i = 0; i < n; i++)
        rt[i] = proc[i].bt;

    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    cout << "\nScheduling Order: ";
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }

        if (!check) {
            t++;
            continue;
        }

        schedulingOrder.push_back(proc[shortest].pid);

        rt[shortest]--;

        minm = rt[shortest];
        if (minm == 0)
            minm = INT_MAX;

        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;

            if (wt[shortest] < 0)
                wt[shortest] = 0;

            proc[shortest].exitTime = finish_time;
        }

        t++;
    }

    for (int i = 0; i < schedulingOrder.size(); i++) {
        cout << "P" << schedulingOrder[i] << " ";
    }

    cout << endl;
}

void displayGanttChart(vector<Process> &proc, vector<int> &schedulingOrder) {
    cout << "\nGantt Chart:\n";
    cout << "Time\t| Execution\n";
    cout << "----------------\n";

    int i = 0;
    for (int time = 0; time < schedulingOrder.size(); time++) {
        cout << time << "\t| Execution P" << schedulingOrder[time] << " (Entry)\n";
        if (time < schedulingOrder.size() - 1 && schedulingOrder[time] != schedulingOrder[time + 1]) {
            cout << time + 1 << "\t| Execution P" << schedulingOrder[time] << " (Exit)\n";
            i++;
        }
    }

    cout << "----------------\n";
}

void findTurnAroundTime(vector<Process> &proc, int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findavgTime(vector<Process> &proc, int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    vector<int> schedulingOrder;

    findWaitingTime(proc, n, wt, schedulingOrder);
    findTurnAroundTime(proc, n, wt, tat);

    displayGanttChart(proc, schedulingOrder);

    cout << "\n P\t\t"
         << "BT\t\t"
         << "WT\t\t"
         << "TAT\t\t\n";

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t\t " << wt[i]
             << "\t\t " << tat[i] << endl;
    }

    cout << "\nAverage waiting time = " << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> proc(n);

    cout << "Enter burst time and arrival time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " burst time: ";
        cin >> proc[i].bt;
        cout << "Process " << i + 1 << " arrival time: ";
        cin >> proc[i].art;
        proc[i].pid = i + 1;
    }

    findavgTime(proc, n);
    return 0;
}
