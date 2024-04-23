#include <iostream>
#include <vector>
#include <omp.h>
#include <time.h>
using namespace std;

int main() {
    // Prompt the user to input the size of the vector
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;

    // Create a vector to store the user input
    vector<int> data(size);

    // Prompt the user to input elements of the vector
    cout << "Enter " << size << " elements of the vector: ";
    for (int i = 0; i < size; ++i) {
        cin >> data[i];
    }

    // Find the minimum value
    int min_value = data[0];
    #pragma omp parallel for reduction(min:min_value)
    for (int i = 0; i < size; ++i) {
        if (data[i] < min_value) {
            min_value = data[i];
        }
    }

    // Find the maximum value
    int max_value = data[0];
    #pragma omp parallel for reduction(max:max_value)
    for (int i = 0; i < size; ++i) {
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }

    // Calculate the sum
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < size; ++i) {
        sum += data[i];
    }

    // Calculate the average
    float average = 0.0;
    #pragma omp parallel for reduction(+:average)
    for (int i = 0; i < size; ++i) {
        average += static_cast<float>(data[i]) / size;
    }

    // Output the results
    cout << "Minimum value: " << min_value << endl;
    cout << "Maximum value: " << max_value << endl;
    cout << "Sum of values: " << sum << endl;
    cout << "Average of values: " << average << endl;

    return 0;
}

