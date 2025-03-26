// ****************** Selection Sort ******************

// Selection Sort is a **comparison-based sorting algorithm** that divides the array into two parts:
// - A **sorted** section (built from left to right).
// - An **unsorted** section (shrinks in each step).
// The algorithm repeatedly selects the **smallest element** from the unsorted section and swaps it 
// with the first unsorted element, placing it in its correct position.  

// **Working Mechanism:**
// 1. Find the **smallest element** in the unsorted section.
// 2. Swap it with the first element of the unsorted section.
// 3. Move to the next position and repeat the process for the remaining elements.
// 4. Continue until the entire array is sorted.

// **Time Complexity:**
// - **Best Case (Already Sorted):** O(n²) (Still scans the entire array).
// - **Worst Case (Reverse Sorted):** O(n²) (Maximum swaps needed).
// - **Average Case:** O(n²) (Always selects the minimum in each pass).

// **Space Complexity:**
// - O(1) → It is an **in-place sorting algorithm**, meaning it does not use extra space.


// ****************** 1️⃣ Implementation of Selection Sort ******************

#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the smallest
        
        // Find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update index of new minimum
            }
        }
        
        // Swap the smallest element with the first unsorted element
        swap(arr[i], arr[minIndex]);
    }
}

// ****************** 2️⃣ Testing the Sorting Algorithm ******************

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    
    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    selectionSort(arr);

    cout << "Sorted Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}

// Explanation:
// - The **outer loop** moves through the array, fixing one element at a time.
// - The **inner loop** finds the smallest element in the remaining unsorted section.
// - The smallest element is swapped with the first element of the unsorted section.


// ****************** 3️⃣ Dry Run of Selection Sort ******************

// Given input: [64, 25, 12, 22, 11]

// **Pass 1:**
// Find the minimum element (11), swap with 64 → [11, 25, 12, 22, 64]

// **Pass 2:**
// Find the minimum element (12), swap with 25 → [11, 12, 25, 22, 64]

// **Pass 3:**
// Find the minimum element (22), swap with 25 → [11, 12, 22, 25, 64]

// **Pass 4:**
// Find the minimum element (25), swap with itself → [11, 12, 22, 25, 64] (Sorted)

// **Final Sorted Array:** [11, 12, 22, 25, 64]


// ****************** 4️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - **Simple and easy to implement**.
// - **Does not require extra memory** (O(1) space complexity).
// - Performs **at most (n-1) swaps**, making it efficient in terms of swap operations.

// ❌ **Disadvantages:**
// - **Inefficient for large datasets** (O(n²) time complexity).
// - Not a **stable sorting algorithm** (may change the relative order of duplicate elements).
// - Always runs in **O(n²)** time, even if the array is already sorted.


// ****************** 5️⃣ Summary ******************

// ✅ **Selection Sort** selects the smallest element from the unsorted section and swaps it.
// ✅ **Time Complexity:** O(n²) in all cases (Best, Worst, and Average).
// ✅ **Space Complexity:** O(1) (in-place sorting).
// ✅ **Not a stable sort** (may change the order of equal elements).
// ✅ **Good when swaps are costly**, as it minimizes swaps compared to Bubble Sort.
// ✅ **Not efficient for large datasets**, better algorithms like Merge Sort and Quick Sort are preferred.

// ✅ Best Practices:
// - **Use Selection Sort** when **minimizing swap operations** is important.
// - **Avoid Selection Sort** for large datasets due to O(n²) complexity.
// - Consider **Insertion Sort** for small arrays as it has O(n) best-case complexity.

