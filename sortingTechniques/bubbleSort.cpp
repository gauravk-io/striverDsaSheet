// ****************** Bubble Sort ******************

// Bubble Sort is a simple **comparison-based sorting algorithm** that repeatedly swaps adjacent elements 
// if they are in the wrong order. The process continues until the array is completely sorted. 
// It is called "Bubble Sort" because larger elements **bubble up** to their correct positions in each pass.

// **Working Mechanism:**
// 1. Start from the first element and compare it with the next one.
// 2. If the first element is greater than the second, swap them.
// 3. Move to the next pair and repeat the process for the entire array.
// 4. The largest element moves to the last position after the first pass.
// 5. Repeat the process for the remaining elements, reducing the comparisons each time.
// 6. The process stops when no swaps are required, indicating that the array is sorted.

// **Time Complexity:**
// - **Best Case (Already Sorted):** O(n) → Only one pass required (with an optimization).
// - **Worst Case (Reverse Sorted):** O(n²) → Maximum swaps occur in each pass.
// - **Average Case:** O(n²) → Random order data takes quadratic time.

// **Space Complexity:**
// - O(1) → It is an **in-place sorting algorithm**, meaning it does not require extra space.


// ****************** 1️⃣ Implementation of Bubble Sort ******************

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped; // To optimize and stop early if already sorted
    
    for (int i = 0; i < n - 1; i++) {
        swapped = false; // Reset swap flag for this pass
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]); // Swap if elements are in wrong order
                swapped = true; // Mark as swapped
            }
        }
        
        if (!swapped) break; // Stop early if no swaps (already sorted)
    }
}

// ****************** 2️⃣ Testing the Sorting Algorithm ******************

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    
    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    bubbleSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

// Explanation:
// - The **inner loop** swaps adjacent elements if needed.
// - The **largest element moves to its correct position** in each pass.
// - If **no swaps occur**, the array is already sorted, and we exit early.


// ****************** 3️⃣ Dry Run of Bubble Sort ******************

// Given input: [5, 1, 4, 2, 8]

// **Pass 1:**
// Compare 5 and 1 → Swap → [1, 5, 4, 2, 8]
// Compare 5 and 4 → Swap → [1, 4, 5, 2, 8]
// Compare 5 and 2 → Swap → [1, 4, 2, 5, 8]
// Compare 5 and 8 → No swap → [1, 4, 2, 5, 8]

// **Pass 2:**
// Compare 1 and 4 → No swap → [1, 4, 2, 5, 8]
// Compare 4 and 2 → Swap → [1, 2, 4, 5, 8]
// Compare 4 and 5 → No swap → [1, 2, 4, 5, 8]

// **Pass 3:**
// Compare 1 and 2 → No swap → [1, 2, 4, 5, 8]
// Compare 2 and 4 → No swap → [1, 2, 4, 5, 8]

// **Pass 4:**
// Compare 1 and 2 → No swap → [1, 2, 4, 5, 8] (Already sorted, exits early)

// **Final Sorted Array:** [1, 2, 4, 5, 8]


// ****************** 4️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - Simple and easy to understand.
// - Requires **no extra memory** (O(1) space complexity).
// - Works well for **small or nearly sorted** datasets (O(n) in best case).
// - Stable sorting algorithm (maintains relative order of equal elements).

// ❌ **Disadvantages:**
// - **Inefficient for large datasets** due to O(n²) time complexity.
// - Much **slower** than efficient sorting algorithms like Quick Sort and Merge Sort.
// - Even optimized versions do not significantly improve performance for large inputs.


// ****************** 5️⃣ Summary ******************

// ✅ **Bubble Sort** repeatedly swaps adjacent elements until sorted.
// ✅ **Time Complexity:** O(n²) in worst and average cases, O(n) in best case (if already sorted).
// ✅ **Space Complexity:** O(1) (in-place sorting).
// ✅ **Stable Sorting Algorithm** (Maintains order of duplicate elements).
// ✅ **Good for small or nearly sorted datasets**, but **not efficient for large data**.
// ✅ **Use optimized Bubble Sort** (with a swap check) to avoid unnecessary passes.

// ✅ Best Practices:
// - **Avoid Bubble Sort** for large data and use **Merge Sort or Quick Sort** instead.
// - **Use the optimized version** to stop early when the array gets sorted.
// - Consider **Insertion Sort** for small datasets, which has O(n) best-case complexity.

