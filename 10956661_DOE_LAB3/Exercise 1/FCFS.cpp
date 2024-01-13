#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// A class to represent a process
class Process {
public:
    int id; // process id
    int burst; // CPU burst time
    int arrival; // arrival time
    int waiting; // waiting time
    int turnaround; // turnaround time

    // Constructor
    Process(int id, int burst, int arrival) {
        this->id = id;
        this->burst = burst;
        this->arrival = arrival;
        this->waiting = 0;
        this->turnaround = 0;
    }
};

// A class to implement FCFS algorithm
class FCFS {
private:
    queue<Process> q; // a queue to store the processes
    vector<Process> order; // a vector to store the scheduling order
    double awt; // average waiting time
    double att; // average turnaround time

public:
    // Constructor
    FCFS(vector<Process> processes) {
        // Sort the processes by arrival time
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.arrival < b.arrival;
        });

        // Enqueue the processes to the queue
        for (Process p : processes) {
            q.push(p);
        }

        // Initialize the average times to zero
        awt = 0;
        att = 0;
    }

    // A function to schedule the processes
    void schedule() {
        int time = 0; // current time
        while (!q.empty()) {
            // Dequeue the first process in the queue
            Process p = q.front();
            q.pop();

            // Update the waiting time and turnaround time of the process
            p.waiting = time - p.arrival;
            p.turnaround = p.waiting + p.burst;

            // Update the current time
            time += p.burst;

            // Update the average times
            awt += p.waiting;
            att += p.turnaround;

            // Add the process to the order vector
            order.push_back(p);
        }

        // Calculate the average times
        awt /= order.size();
        att /= order.size();
    }

    // A function to display the scheduling order
    void displayOrder() {
        cout << "Scheduling order: ";
        for (Process p : order) {
            cout << "P" << p.id << " ";
        }
        cout << "\n";
    }

    // A function to display the details of each process
    void displayProcessDetails() {
        cout << "Process Details:\n";
        cout << "P\tBT\tAT\tWT\tTAT\n";
        for (Process p : order) {
            cout << p.id << "\t" << p.burst << "\t" << p.arrival << "\t" << p.waiting << "\t" << p.turnaround << "\n";
        }
    }

    // A function to display the average waiting time
    void displayAWT() {
        cout << "Average waiting time: " << awt << "\n";
    }

    // A function to display the average turnaround time
    void displayATT() {
        cout << "Average turnaround time: " << att << "\n";
    }
};

int main() {
    int numProcesses;
    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    // Example usage
    vector<Process> processes;
    for (int i = 1; i <= numProcesses; ++i) {
        int burst, arrival;
        cout << "Enter burst time for process P" << i << ": ";
        cin >> burst;
        cout << "Enter arrival time for process P" << i << ": ";
        cin >> arrival;
        processes.push_back(Process(i, burst, arrival));
    }

    FCFS fcfs(processes);
    fcfs.schedule();
    fcfs.displayOrder();
    fcfs.displayProcessDetails();
    fcfs.displayAWT();
    fcfs.displayATT();

    return 0;
}
