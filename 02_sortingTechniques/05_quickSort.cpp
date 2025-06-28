// ****************** Quick Sort ******************

// **Quick Sort** is a **divide and conquer** sorting algorithm that selects a pivot element,
// partitions the array around the pivot, and recursively sorts the left and right partitions.

// **Working Mechanism:**
// 1. **Choose a Pivot**: Select an element as the pivot (can be first, last, or middle element).
// 2. **Partitioning**: Reorder elements so that:
//    - Elements **smaller** than pivot go to the **left**.
//    - Elements **greater** than pivot go to the **right**.
// 3. **Recursion**: Recursively apply quick sort to the left and right partitions.
// 4. **Base Case**: When a partition has one or zero elements, it is already sorted.

// **Time Complexity:**
// - **Best Case:** O(n log n) (Balanced partitions).
// - **Worst Case:** O(n²) (Unbalanced partitions, e.g., already sorted array with bad pivot selection).
// - **Average Case:** O(n log n).

// **Space Complexity:**
// - O(log n) for recursion stack (in-place sorting).


// ****************** 1️⃣ Implementation of Quick Sort ******************

#include <bits/stdc++.h>
using namespace std;

// Partition function to place the pivot at the correct position
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;       // Index for smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in the correct position
    return i + 1;
}

// QuickSort function (recursive)
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        quickSort(arr, low, pi - 1);  // Sort left half
        quickSort(arr, pi + 1, high); // Sort right half
    }
}

// ****************** 2️⃣ Testing the Sorting Algorithm ******************

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

// Explanation:
// - The function **quickSort()** selects a pivot and partitions the array around it.
// - The function **partition()** places the pivot in its correct position and moves smaller elements to the left and larger elements to the right.


// ****************** 3️⃣ Dry Run of Quick Sort ******************

// Given input: [10, 7, 8, 9, 1, 5]

// **Step 1: Choose Pivot (last element 5)**
// Partition: [1] 5 [10, 7, 8, 9]
// Pivot placed at index 1

// **Step 2: Recursively sort left and right**
// Left: Already sorted [1]
// Right: Pivot = 9 → Partition: [7, 8] 9 [10]
// Pivot placed at index 4

// **Step 3: Recursively sort right part**
// Left: Pivot = 8 → Partition: [7] 8
// Sorted array: [1, 5, 7, 8, 9, 10]

// **Final Sorted Array:** [1, 5, 7, 8, 9, 10]


// ****************** 4️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - **In-place sorting algorithm** (O(log n) extra space).
// - **Best case O(n log n) time complexity**, making it **efficient** for large datasets.
// - **Faster than Merge Sort** on average due to fewer swaps and memory access.
// - **Tail-recursive**, can be optimized to iterative.

// ❌ **Disadvantages:**
// - **Worst case O(n²) when the pivot is poorly chosen** (e.g., sorted array with first/last element pivot).
// - **Not stable** (relative order of equal elements may change).
// - **Recursion depth can be large**, leading to stack overflow in unoptimized cases.


// ****************** 5️⃣ Summary ******************

// ✅ **Quick Sort** is a **divide and conquer** algorithm that selects a pivot and partitions the array around it.
// ✅ **Time Complexity:**
//    - Best: **O(n log n)** (balanced partitions).
//    - Worst: **O(n²)** (unbalanced partitions).
//    - Average: **O(n log n)**.
// ✅ **Space Complexity:** O(log n) (in-place sorting).
// ✅ **Fast and efficient for large datasets** but **unstable** (may change order of equal elements).
// ✅ **Best pivot selection (e.g., median of three)** helps prevent worst-case performance.

