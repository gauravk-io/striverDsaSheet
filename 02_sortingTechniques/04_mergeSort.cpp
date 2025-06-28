// ****************** Merge Sort ******************

// **Merge Sort** is a **divide and conquer** sorting algorithm that splits an array into smaller subarrays,
// sorts them recursively, and then merges the sorted subarrays to produce the final sorted array.

// **Working Mechanism:**
// 1. **Divide**: Split the array into two halves until each subarray contains only one element.
// 2. **Conquer**: Recursively sort both halves.
// 3. **Merge**: Combine the two sorted halves to get the final sorted array.

// **Time Complexity:**
// - **Best Case:** O(n log n) (Always splits and merges).
// - **Worst Case:** O(n log n) (Splitting and merging are always required).
// - **Average Case:** O(n log n).

// **Space Complexity:**
// - O(n) → **Not in-place** (Requires extra space for merging).


// ****************** 1️⃣ Implementation of Merge Sort ******************

#include <bits/stdc++.h>
using namespace std;

// Merge two sorted subarrays arr[left...mid] and arr[mid+1...right]
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> leftArr(n1), rightArr(n2);

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merge the two subarrays
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i++];
        } else {
            arr[k] = rightArr[j++];
        }
        k++;
    }

    // Copy any remaining elements
    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

// Recursive function to sort the array
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // Sort left half
        mergeSort(arr, mid + 1, right);  // Sort right half
        merge(arr, left, mid, right);    // Merge sorted halves
    }
}

// ****************** 2️⃣ Testing the Sorting Algorithm ******************

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

// Explanation:
// - The function **mergeSort()** divides the array into two halves recursively.
// - The function **merge()** merges two sorted halves back into a sorted array.


// ****************** 3️⃣ Dry Run of Merge Sort ******************

// Given input: [12, 11, 13, 5, 6, 7]

// **Step 1: Divide the array**
// [12, 11, 13]  and  [5, 6, 7]

// **Step 2: Recursively divide each half**
// [12, 11]  [13]    and    [5, 6]  [7]
// [12] [11] [13]    and    [5] [6] [7]

// **Step 3: Merge sorted subarrays**
// Merge [12] and [11] → [11, 12]
// Merge [11, 12] and [13] → [11, 12, 13]
// Merge [5] and [6] → [5, 6]
// Merge [5, 6] and [7] → [5, 6, 7]

// **Step 4: Merge final halves**
// Merge [11, 12, 13] and [5, 6, 7] → [5, 6, 7, 11, 12, 13]

// **Final Sorted Array:** [5, 6, 7, 11, 12, 13]


// ****************** 4️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - **Guaranteed O(n log n) time complexity** in all cases.
// - **Stable sort** (Maintains order of equal elements).
// - **Efficient for large datasets** compared to O(n²) sorting algorithms (Bubble, Insertion, Selection).
// - Works well for **linked lists** because merging does not require shifting elements.

// ❌ **Disadvantages:**
// - **Requires extra memory O(n)** for temporary arrays (not in-place).
// - **Slower for small datasets** due to recursive overhead.
// - **More complex than simple sorting algorithms** like Insertion or Selection Sort.


// ****************** 5️⃣ Summary ******************

// ✅ **Merge Sort** is a **divide and conquer** algorithm that recursively splits the array and merges sorted halves.
// ✅ **Time Complexity:**
//    - Best: **O(n log n)**.
//    - Worst: **O(n log n)**.
//    - Average: **O(n log n)**.
// ✅ **Space Complexity:** O(n) (extra space for merging).
// ✅ **Stable sorting algorithm** (maintains order of equal elements).
// ✅ **Best for large datasets**, but **not ideal for small arrays** due to recursion overhead.
// ✅ **Preferred for linked lists** since merging does not require extra memory.

