#include <iostream>
#include <vector>
#include <queue>
#include <functional>
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
    int entryTime; // entry time
    int exitTime; // exit time

    // Constructor
    Process(int id, int burst, int arrival) {
        this->id = id;
        this->burst = burst;
        this->arrival = arrival;
        this->waiting = 0;
        this->turnaround = 0;
        this->entryTime = 0;
        this->exitTime = 0;
    }
};

// A class to implement SJN algorithm
class SJN {
private:
    priority_queue<Process, vector<Process>, function<bool(Process, Process)>> pq; // a priority queue to store the processes
    vector<Process> order; // a vector to store the scheduling order
    double awt; // average waiting time
    double att; // average turnaround time
    vector<Process> processes; // added member variable for processes

public:
    // Constructor
    SJN(vector<Process> processes) : processes(processes) {
        // Sort the processes by arrival time
        sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
            return a.arrival < b.arrival;
        });

        // Define the comparator function for the priority queue
        auto comp = [](const Process& a, const Process& b) {
            // If the burst times are equal, compare by arrival times
            if (a.burst == b.burst) {
                return a.arrival > b.arrival;
            }
            // Otherwise, compare by burst times
            return a.burst > b.burst;
        };

        // Initialize the priority queue with the comparator function
        pq = priority_queue<Process, vector<Process>, function<bool(Process, Process)>>(comp);

        // Enqueue the first process to the priority queue
        pq.push(processes[0]);

        // Initialize the average times to zero
        awt = 0;
        att = 0;
    }

    // A function to schedule the processes
    void schedule() {
        int time = 0; // current time
        int index = 1; // index of the next process to be enqueued
        while (!pq.empty()) {
            // Dequeue the highest priority process in the queue
            Process p = pq.top();
            pq.pop();

            // Update the entry time
            p.entryTime = time;

            // Update the waiting time and turnaround time of the process
            p.waiting = time - p.arrival;
            p.turnaround = p.waiting + p.burst;

            // Update the current time
            time += p.burst;

            // Update the exit time
            p.exitTime = time;

            // Update the average times
            awt += p.waiting;
            att += p.turnaround;

            // Add the process to the order vector
            order.push_back(p);

            // Enqueue the next processes that have arrived before or at the current time
            while (index < processes.size() && processes[index].arrival <= time) {
                pq.push(processes[index]);
                index++;
            }
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
        cout << "P\tBT\tAT\tEntry\tExit\tWT\tTAT\n";
        for (Process p : order) {
            cout << p.id << "\t" << p.burst << "\t" << p.arrival << "\t" << p.entryTime << "\t" << p.exitTime
                 << "\t" << p.waiting << "\t" << p.turnaround << "\n";
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

    // A function to display the Gantt Chart table
    void displayGanttChart() {
        cout << "Gantt Chart:\n";
        cout << "Time\t| Process\n";
        cout << "----------------\n";
        for (Process p : order) {
            cout << p.entryTime << "\t| P" << p.id << "\n";
            cout << p.exitTime << "\t| \n";
            cout << "----------------\n";
        }
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

    SJN sjn(processes);
    sjn.schedule();
    sjn.displayOrder();
    cout<<endl;
    sjn.displayGanttChart();
    cout<<endl;
    sjn.displayProcessDetails();
    cout<<endl;
    sjn.displayAWT();
    sjn.displayATT();


    return 0;
}
