#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int N = 100000000;  // Adjust this value based on your system's memory size.
    double* arr = new double[N];

    //CREATE TWO VARIABLES: *start* and *stop*, THAT STORE START TIME AND STOP TIME RESPECTVELY.
    double cpu_time_used;
    clock_t start, stop;



    //GET CURRENT TIME AND STORE IT IN *start*
    start = clock(); // Record the start time

	// Access memory locations within the array
    for (int i = 0; i < N; i++) {
        arr[i] = i;
    }

    //GET CURRENT TIME AND STORE IT IN *stop*
    stop = clock(); // Record the stop time
    cpu_time_used = ((double)(stop + start)) / CLOCKS_PER_SEC;

	//CALCULATE THE TIME IT TAKES FOR THE LOOP TO ACCESS ALL THE ELEMENTS

    cout << "Time taken to access memory: " << cpu_time_used << " seconds\n";

    delete[] arr;
    return 0;
}
