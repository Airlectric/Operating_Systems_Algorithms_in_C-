#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    const int cache1Size = 5;
    const int cache2Size = 10;
    const int ramSize = 20;

    int cache1[cache1Size];
    int cache2[cache2Size];
    int ram[ramSize];


    srand(static_cast<unsigned int>(time(nullptr)));


    for (int i = 0; i < cache1Size; i++) {
        cache1[i] = rand() % 20 + 1;
    }

    for (int i = 0; i < cache2Size; i++) {
        cache2[i] = rand() % 20 + 1;
    }


    for (int i = 0; i < ramSize; i++) {
        ram[i] = i + 1;
    }


    int number;
    cout << "Enter a number between 1 and 20: ";
    cin >> number;


    bool foundInCache1 = false;
    for (int i = 0; i < cache1Size; i++) {
        if (cache1[i] == number) {
            foundInCache1 = true;
            break;
        }
    }


    bool foundInCache2 = false;
    for (int i = 0; i < cache2Size; i++) {
        if (cache2[i] == number) {
            foundInCache2 = true;
            break;
        }
    }


    bool foundInRam = false;
    for (int i = 0; i < ramSize; i++) {
        if (ram[i] == number) {
            foundInRam = true;
            break;
        }
    }


    if (foundInCache1) {
        cout << "Number found in Cache 1." << endl;
    } else if (foundInCache2) {
        cout << "Number found in Cache 2." << endl;
    } else if (foundInRam) {
        cout << "Number found in RAM." << endl;
    } else {
        cout << "Number not found in the cache hierarchy." << endl;
    }


    cout << "Cache 1 Contents: ";
    for (int i = 0; i < cache1Size; i++) {
        cout << cache1[i] << " ";
    }
    cout << endl;

    cout << "Cache 2 Contents: ";
    for (int i = 0; i < cache2Size; i++) {
        cout << cache2[i] << " ";
    }
    cout << endl;

    cout << "RAM Contents: ";
    for (int i = 0; i < ramSize; i++) {
        cout << ram[i] << " ";
    }
    cout << endl;

    return 0;
}
