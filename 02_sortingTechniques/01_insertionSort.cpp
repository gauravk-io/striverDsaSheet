// ****************** Insertion Sort ******************

// **Insertion Sort** is a simple **comparison-based** sorting algorithm that builds the sorted array one element at a time.
// It works similarly to sorting playing cards in your hand:
// - Start with the first element (consider it sorted).
// - Take the next element and place it in the correct position within the sorted part.
// - Repeat this for all elements until the entire array is sorted.

// **Working Mechanism:**
// 1. Pick the second element and compare it with the first element.
// 2. If smaller, shift the first element to the right and insert the picked element at the correct position.
// 3. Repeat the process for the remaining elements, expanding the sorted part.

// **Time Complexity:**
// - **Best Case (Already Sorted):** O(n) (Each element is compared only once).
// - **Worst Case (Reverse Sorted):** O(n²) (Each element is compared with all previous elements).
// - **Average Case:** O(n²) (Each element is inserted into the correct position).

// **Space Complexity:**
// - O(1) → **In-place sorting**, meaning no extra memory is required.


// ****************** 1️⃣ Implementation of Insertion Sort ******************

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key; // Insert key at the correct position
    }
}

// ****************** 2️⃣ Testing the Sorting Algorithm ******************

int main() {
    vector<int> arr = {12, 11, 13, 5, 6};
    
    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    insertionSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

// Explanation:
// - The **outer loop** picks an element from the unsorted section.
// - The **inner loop** shifts elements in the sorted section to make space for insertion.
// - The **key** is inserted at the correct position.


// ****************** 3️⃣ Dry Run of Insertion Sort ******************

// Given input: [12, 11, 13, 5, 6]

// **Pass 1 (i = 1, key = 11):**
// Compare 11 with 12, shift 12 → [12, 12, 13, 5, 6]
// Insert 11 → [11, 12, 13, 5, 6]

// **Pass 2 (i = 2, key = 13):**
// 13 is already in the correct place → [11, 12, 13, 5, 6]

// **Pass 3 (i = 3, key = 5):**
// Compare 5 with 13, shift 13 → [11, 12, 13, 13, 6]
// Compare 5 with 12, shift 12 → [11, 12, 12, 13, 6]
// Compare 5 with 11, shift 11 → [11, 11, 12, 13, 6]
// Insert 5 → [5, 11, 12, 13, 6]

// **Pass 4 (i = 4, key = 6):**
// Compare 6 with 13, shift 13 → [5, 11, 12, 13, 13]
// Compare 6 with 12, shift 12 → [5, 11, 12, 12, 13]
// Compare 6 with 11, shift 11 → [5, 11, 11, 12, 13]
// Insert 6 → [5, 6, 11, 12, 13] (Sorted)

// **Final Sorted Array:** [5, 6, 11, 12, 13]


// ****************** 4️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - **Efficient for small datasets** and nearly sorted arrays.
// - **Stable sort** (Maintains the order of equal elements).
// - **In-place sorting algorithm**, requiring no extra memory (O(1) space).
// - **Best case runs in O(n) time**, making it faster than Bubble Sort and Selection Sort for nearly sorted inputs.

// ❌ **Disadvantages:**
// - **Inefficient for large datasets** due to O(n²) worst-case time complexity.
// - **Slower than advanced sorting algorithms** like Merge Sort and Quick Sort.
// - Requires **multiple shifts** per insertion, making it slow for large numbers of elements.


// ****************** 5️⃣ Summary ******************

// ✅ **Insertion Sort** works by inserting each element at its correct position in the sorted section.
// ✅ **Time Complexity:**
//    - Best: **O(n)** (Already sorted).
//    - Worst: **O(n²)** (Reverse sorted).
//    - Average: **O(n²)**.
// ✅ **Space Complexity:** O(1) (in-place sorting).
// ✅ **Stable sorting algorithm** (does not change relative order of equal elements).
// ✅ **Good for small or nearly sorted datasets**, but inefficient for large datasets.
// ✅ **Preferred for online sorting**, where new elements are continuously added to an existing sorted list.

// ✅ Best Practices:
// - **Use Insertion Sort** when the input is **small or nearly sorted**.
// - **Avoid for large datasets** where better alternatives like Quick Sort or Merge Sort exist.
// - **Use for linked lists**, as it does not require shifting elements like arrays.

