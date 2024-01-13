#include <iostream>

using namespace std;

int main() {
    char choice;
    cout << "Choose a memory configuration (a, b, or c):\n";
    cout << "a) Computer with only main memory\n";
    cout << "b) Computer with a one-level cache and main memory\n";
    cout << "c) Computer with a two-level cache and main memory\n";
    cin >> choice;

    double T1, T2, T3, H1, H2, Ts;

    cout << "Enter access time for memory level 1 (T1): ";
    cin >> T1;

    if (choice == 'b' || choice == 'c') {
        cout << "Enter hit ratio for memory level 1 (H1): ";
        cin >> H1;
    }

    if (choice == 'b' || choice == 'c') {
        cout << "Enter access time for memory level 2 (T2): ";
        cin >> T2;
        cout << "Enter hit ratio for memory level 2 (H2): ";
        cin >> H2;
    }

    if (choice == 'c') {
        cout << "Enter access time for memory level 3 (T3): ";
        cin >> T3;
    }


    if (choice == 'a') {
        Ts = T1;
    } else if (choice == 'b') {
        Ts = T1 + (1 - H1) * T2;
    } else if (choice == 'c'){
    Ts = T1 + (1 - H1) * (H2 * (T1 + T2) + (1 - H2) * (T1 + T2 + T3));
}


    cout << "Average Memory Access Time: " << Ts << " microseconds\n";

    return 0;
}
