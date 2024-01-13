#include <iostream>
#include <cstdlib>
#include <ctime>
#include "SystemCall.h"

using namespace std;

const int CACHE1_SIZE = 5;
const int CACHE2_SIZE = 10;
const int RAM_SIZE = 20;

int cache1[CACHE1_SIZE];
int cache2[CACHE2_SIZE];
int ram[RAM_SIZE];

void InitializeCaches() {
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < CACHE1_SIZE; i++) {
        cache1[i] = rand() % 20 + 1;
    }

    for (int i = 0; i < CACHE2_SIZE; i++) {
        cache2[i] = rand() % 20 + 1;
    }

    for (int i = 0; i < RAM_SIZE; i++) {
        ram[i] = i + 1;
    }
}

bool SearchInCache(int number, int cache[], int cacheSize) {
    for (int i = 0; i < cacheSize; i++) {
        if (cache[i] == number) {
            return true;
        }
    }
    return false;
}

bool SearchInRam(int number) {
    for (int i = 0; i < RAM_SIZE; i++) {
        if (ram[i] == number) {
            return true;
        }
    }
    return false;
}

void ReplaceInCache1(int number) {
    cache1[0] = number;
}

void DisplayMemoryContents() {
    cout << "Cache 1 Contents: ";
    for (int i = 0; i < CACHE1_SIZE; i++) {
        cout << cache1[i] << " ";
    }
    cout << endl;

    cout << "Cache 2 Contents: ";
    for (int i = 0; i < CACHE2_SIZE; i++) {
        cout << cache2[i] << " ";
    }
    cout << endl;

    cout << "RAM Contents: ";
    for (int i = 0; i < RAM_SIZE; i++) {
        cout << ram[i] << " ";
    }
    cout << endl;
}

int main() {
    InitializeCaches();

    int userInput = AcceptUserInput();
    if (IsValidInput(userInput)) {
        bool foundInCache1 = SearchInCache(userInput, cache1, CACHE1_SIZE);
        bool foundInCache2 = SearchInCache(userInput, cache2, CACHE2_SIZE);
        bool foundInRam = SearchInRam(userInput);

        if (foundInCache1) {
            cout << "Number found in Cache 1." <<endl<< endl;
        } else if (foundInCache2) {
            cout << "Number found in Cache 2." <<endl<< endl;
        } else if (foundInRam) {
            cout << "Number found in RAM." <<endl<< endl;
        }

        if (!SearchInCache(userInput, cache1, CACHE1_SIZE)) {
            cout<<userInput<<" was not found in cache 1"<<endl<<endl;
            cout<<userInput<<" has been added to and replaces the first element in cache 1"<<endl<<endl;
            ReplaceInCache1(userInput);
        }

        DisplayMemoryContents();
    } else {
        cout << "Invalid input." << endl;
    }

    return 0;
}
