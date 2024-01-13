#include "SystemCall.h"
#include <iostream>
#include <limits>

using namespace std;

int AcceptUserInput() {
    int input;
    cout << "Enter an integer: ";
    while (!(cin >> input) || cin.peek() != '\n') {
        cout << "Invalid input. Please enter an integer: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

bool IsValidInput(int input) {
    return (input >= 1 && input <= 20 && input == static_cast<int>(input));
}

void DisplayMemoryInfo(int memoryLocation) {
    cout << "Memory location: ";
    if (memoryLocation == 1) {
        cout << "Cache 1" << endl;
    } else if (memoryLocation == 2) {
        cout << "Cache 2" << endl;
    } else if (memoryLocation == 3) {
        cout << "RAM" << endl;
    }
}
