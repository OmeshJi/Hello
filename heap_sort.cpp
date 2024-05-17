#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i, int& comparisons) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // left = 2*i + 1
    int right = 2 * i + 2;  // right = 2*i + 2

    // Compare root with left child
    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest])
            largest = left;
    }

    // Compare largest so far with right child
    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    // Change root, if needed
    if (largest != i) {
        swap(arr[i], arr[largest]);  // Swap

        // Heapify the root
        heapify(arr, n, largest, comparisons);
    }
}

// Main function to perform Heap Sort
void heapSort(vector<int>& arr, int& comparisons) {
    int n = arr.size();

    // Build a maxheap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0, comparisons);
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

// Main function
int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int comparisons = 0;

    cout << "Original array:\n";
    printArray(arr);

    heapSort(arr, comparisons);

    cout << "Sorted array:\n";
    printArray(arr);

    cout << "Number of comparisons: " << comparisons << endl;

    return 0;
}
