// ****************** Heap Sort ******************

// **Heap Sort** is a **comparison-based** sorting algorithm that uses a **binary heap** data structure.
// It repeatedly extracts the **maximum (or minimum) element** from the heap and places it in the sorted position.

// **Working Mechanism:**
// 1. **Build a Max Heap**: Convert the input array into a **max heap** (largest element at the root).
// 2. **Extract Maximum**: Swap the root (largest element) with the last element and reduce the heap size.
// 3. **Heapify**: Restore the max heap property.
// 4. **Repeat** until the heap is empty and the array is sorted.

// **Time Complexity:**
// - **Best Case:** O(n log n) (Heap construction + sorting).
// - **Worst Case:** O(n log n) (Always log n swaps).
// - **Average Case:** O(n log n).

// **Space Complexity:**
// - O(1) (In-place sorting, no extra array needed).


// ****************** 1️⃣ Implementation of Heap Sort ******************

#include <bits/stdc++.h>
using namespace std;

// Function to heapify a subtree rooted at index `i`
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;     // Root element
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than the current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and recursively heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Step 2: Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move root to the end
        heapify(arr, i, 0);    // Restore heap property
    }
}

// ****************** 2️⃣ Testing the Sorting Algorithm ******************

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    heapSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

// Explanation:
// - The **heapify()** function maintains the heap structure.
// - The **heapSort()** function builds the max heap and repeatedly extracts the largest element.


// ****************** 3️⃣ Dry Run of Heap Sort ******************

// Given input: [12, 11, 13, 5, 6, 7]

// **Step 1: Build Max Heap**
// - Convert array into max heap: [13, 11, 12, 5, 6, 7]

// **Step 2: Extract Maximum**
// - Swap 13 and last element → [7, 11, 12, 5, 6, 13]
// - Heapify → [12, 11, 7, 5, 6, 13]

// - Swap 12 and last element → [6, 11, 7, 5, 12, 13]
// - Heapify → [11, 6, 7, 5, 12, 13]

// - Continue extracting until sorted...

// **Final Sorted Array:** [5, 6, 7, 11, 12, 13]


// ****************** 4️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - **O(n log n) time complexity** for all cases (better than Quick Sort's worst case).
// - **In-place sorting (O(1) extra space)** unlike Merge Sort (O(n) space).
// - **Efficient for large datasets and priority queues**.

// ❌ **Disadvantages:**
// - **Not a stable sort** (relative order of equal elements may change).
// - **More memory writes** compared to Quick Sort, making it slower in practice.
// - **Not cache friendly** due to non-sequential memory access.


// ****************** 5️⃣ Summary ******************

// ✅ **Heap Sort** is a **comparison-based sorting algorithm** using a **binary heap**.
// ✅ **Time Complexity:**
//    - Best: **O(n log n)**.
//    - Worst: **O(n log n)**.
//    - Average: **O(n log n)**.
// ✅ **Space Complexity:** O(1) (in-place sorting).
// ✅ **Useful for priority queues** but **not stable**.
// ✅ **Works well when constant time access to largest/smallest element is required**.

