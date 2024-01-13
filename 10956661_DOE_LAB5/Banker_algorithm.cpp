#include <iostream>

using namespace std;

class Process {
public:
    char state;
    int r1, r2, r3;

    Process() : state(' '), r1(0), r2(0), r3(0) {}
};

class Banker {
private:
    int R1, R2, R3;

public:
    Banker() {
        cout << "Enter total number of instances for resource R1: ";
        cin >> R1;

        cout << "Enter total number of instances for resource R2: ";
        cin >> R2;

        cout << "Enter total number of instances for resource R3: ";
        cin >> R3;
    }

    void validate(Process& p, int maxR1, int maxR2, int maxR3) {
        if (maxR1 <= R1 && maxR2 <= R2 && maxR3 <= R3) {
            R1 -= maxR1;
            R2 -= maxR2;
            R3 -= maxR3;
            p.r1 += maxR1;
            p.r2 += maxR2;
            p.r3 += maxR3;
            p.state = 'S'; // Safe state
        } else {
            p.state = 'U'; // Unsafe state
        }
    }

    void display(Process& p) {
        cout << "Process State: " << p.state << "\n";
        cout << "R1: " << p.r1 << " R2: " << p.r2 << " R3: " << p.r3 << "\n\n";
    }

    void displayAll(Process& p1, Process& p2, Process& p3) {
        cout << "Process P1:\n";
        display(p1);

        cout << "Process P2:\n";
        display(p2);

        cout << "Process P3:\n";
        display(p3);
    }

    void allocateResources(Process& p1, Process& p2, Process& p3) {
        int maxR1, maxR2, maxR3;

        cout << "Enter maximum required resources for Process P1 (R1 R2 R3): ";
        cin >> maxR1 >> maxR2 >> maxR3;
        validate(p1, maxR1, maxR2, maxR3);

        cout << "Enter maximum required resources for Process P2 (R1 R2 R3): ";
        cin >> maxR1 >> maxR2 >> maxR3;
        validate(p2, maxR1, maxR2, maxR3);

        cout << "Enter maximum required resources for Process P3 (R1 R2 R3): ";
        cin >> maxR1 >> maxR2 >> maxR3;
        validate(p3, maxR1, maxR2, maxR3);
    }
};

int main() {
    Banker banker;
    Process p1, p2, p3;

    banker.allocateResources(p1, p2, p3);

    banker.displayAll(p1, p2, p3);

    cout << "Resource request will result in a ";
    if (p1.state == 'U' || p2.state == 'U' || p3.state == 'U') {
        cout << "UNSAFE state.\n";
        if (p1.state == 'U') cout << "Process P1 caused the unsafe state.\n";
        if (p2.state == 'U') cout << "Process P2 caused the unsafe state.\n";
        if (p3.state == 'U') cout << "Process P3 caused the unsafe state.\n";
    } else {
        cout << "SAFE state.\n";
    }

    return 0;
}
