// ****************** Check if an Array is Sorted ******************

// ****************** Problem Statement ******************
// Given an array, determine if it is sorted in non-decreasing order.

// ****************** Brute Force Approach ******************
// - Create a sorted copy of the array.
// - Compare it with the original array.

#include <bits/stdc++.h>
using namespace std;

bool isSortedBruteForce(vector<int>& arr) {
    vector<int> sortedArr = arr; // Copy original array
    sort(sortedArr.begin(), sortedArr.end()); // Sort the copy
    return arr == sortedArr; // Compare original with sorted version
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << (isSortedBruteForce(arr) ? "Sorted" : "Not Sorted") << endl;
    return 0;
}

// Time Complexity: O(N log N) (due to sorting)
// Space Complexity: O(N) (extra space for copy)

// ****************** Better Approach ******************
// - Compare adjacent elements in a single loop.

bool isSortedBetter(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << (isSortedBetter(arr) ? "Sorted" : "Not Sorted") << endl;
    return 0;
}

// Time Complexity: O(N) (single pass)
// Space Complexity: O(1) (constant space)

// ****************** Optimal Approach ******************
// - Same as the better approach; no further optimization is possible.

// ****************** Dry Run ******************
// Input: [1, 2, 3, 4, 5]
// Iteration 1: 2 ≥ 1 ✅
// Iteration 2: 3 ≥ 2 ✅
// Iteration 3: 4 ≥ 3 ✅
// Iteration 4: 5 ≥ 4 ✅
// Output: Sorted

// ****************** Advantages ******************
// ✅ Optimal approach runs in O(N) time with O(1) space.
// ✅ No modifications needed on the array.

// ****************** Disadvantages ******************
// ❌ Brute force (sorting) approach is unnecessary and inefficient.

// ****************** Summary ******************
// - Sorting-based approach is O(N log N) and inefficient.
// - Single-pass comparison (O(N)) is the best approach.
