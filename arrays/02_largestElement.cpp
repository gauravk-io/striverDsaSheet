// ****************** Find Largest Element in an Array ******************

// ****************** Problem Statement ******************
// Given an array of N elements, find the largest element in the array.

// ****************** Brute Force Approach ******************
// - Sort the array in ascending order.
// - The last element will be the largest.

#include <bits/stdc++.h>
using namespace std;

int findLargestBruteForce(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // Sort the array
    return arr.back(); // Return the last element
}

int main() {
    vector<int> arr = {3, 1, 7, 9, 5};
    cout << "Largest Element: " << findLargestBruteForce(arr) << endl;
    return 0;
}

// Time Complexity: O(N log N) (due to sorting)
// Space Complexity: O(1) (in-place sorting)

// ****************** Better Approach ******************
// - Use a linear scan and store the maximum element.

int findLargestBetter(vector<int>& arr) {
    int maxElement = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    return maxElement;
}

int main() {
    vector<int> arr = {3, 1, 7, 9, 5};
    cout << "Largest Element: " << findLargestBetter(arr) << endl;
    return 0;
}

// Time Complexity: O(N) (single pass)
// Space Complexity: O(1) (constant space)

// ****************** Optimal Approach ******************
// The better approach is already optimal (O(N) time, O(1) space).

// ****************** Dry Run ******************
// Input: [3, 1, 7, 9, 5]
// Iteration 1: maxElement = 3
// Iteration 2: maxElement = 3 (1 < 3)
// Iteration 3: maxElement = 7 (7 > 3)
// Iteration 4: maxElement = 9 (9 > 7)
// Iteration 5: maxElement = 9 (5 < 9)
// Output: 9

// ****************** Advantages ******************
// ✅ Better approach takes O(N) time and is optimal.
// ✅ Space complexity is O(1), making it efficient for large arrays.

// ****************** Disadvantages ******************
// ❌ Brute force (sorting) is inefficient for large arrays (O(N log N) time).
// ❌ Sorting modifies the original array if not done on a copy.

// ****************** Summary ******************
// - Sorting-based approach is O(N log N), but unnecessary.
// - The best approach is a single-pass linear scan (O(N)) with O(1) space.
