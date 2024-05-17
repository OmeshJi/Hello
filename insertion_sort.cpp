#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to perform Insertion Sort and count comparisons
void insertionSort(vector<int>& arr, int& comparisons) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0) {
            comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
}

// Function to generate a random integer between min and max
int getRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

// Main function
int main() {
    srand(time(0));  // Seed the random number generator

    const int numArrays = 100;  // Number of arrays to generate

    for (int i = 0; i < numArrays; ++i) {
        // Generate a random size for the array between 30 and 1000
        int size = getRandomNumber(30, 1000);
        vector<int> arr(size);

        // Fill the array with random integers
        for (int& num : arr) {
            num = getRandomNumber(1, 1000);
        }

        int comparisons = 0;
        insertionSort(arr, comparisons);

        cout << " Size = " << size << ", Comparisons = " << comparisons << endl;
    }

    return 0;
}
