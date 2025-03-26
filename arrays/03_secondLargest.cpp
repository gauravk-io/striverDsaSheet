// ****************** Find Second Largest Element in an Array ******************

// ****************** Problem Statement ******************
// Given an array of N elements, find the second largest element in the array.

// ****************** Brute Force Approach ******************
// - Sort the array in ascending order.
// - The second last element will be the second largest.

#include <bits/stdc++.h>
using namespace std;

int findSecondLargestBruteForce(vector<int>& arr) {
    sort(arr.begin(), arr.end()); // Sort the array
    return arr[arr.size() - 2]; // Return the second last element
}

int main() {
    vector<int> arr = {3, 1, 7, 9, 5};
    cout << "Second Largest Element: " << findSecondLargestBruteForce(arr) << endl;
    return 0;
}

// Time Complexity: O(N log N) (due to sorting)
// Space Complexity: O(1) (in-place sorting)

// ****************** Better Approach ******************
// - Find the largest element in one pass.
// - In another pass, find the largest element smaller than the maximum.

int findSecondLargestBetter(vector<int>& arr) {
    int maxElement = INT_MIN, secondMax = INT_MIN;

    // Find the largest element
    for (int num : arr) {
        maxElement = max(maxElement, num);
    }

    // Find the second largest element
    for (int num : arr) {
        if (num < maxElement) {
            secondMax = max(secondMax, num);
        }
    }

    return secondMax;
}

int main() {
    vector<int> arr = {3, 1, 7, 9, 5};
    cout << "Second Largest Element: " << findSecondLargestBetter(arr) << endl;
    return 0;
}

// Time Complexity: O(2N) ≈ O(N) (two passes)
// Space Complexity: O(1) (constant space)

// ****************** Optimal Approach ******************
// - Use a single pass to find both largest and second largest.

int findSecondLargestOptimal(vector<int>& arr) {
    int maxElement = INT_MIN, secondMax = INT_MIN;

    for (int num : arr) {
        if (num > maxElement) {
            secondMax = maxElement;
            maxElement = num;
        } else if (num > secondMax && num < maxElement) {
            secondMax = num;
        }
    }

    return secondMax;
}

int main() {
    vector<int> arr = {3, 1, 7, 9, 5};
    cout << "Second Largest Element: " << findSecondLargestOptimal(arr) << endl;
    return 0;
}

// Time Complexity: O(N) (single pass)
// Space Complexity: O(1) (constant space)

// ****************** Dry Run ******************
// Input: [3, 1, 7, 9, 5]
// Iteration 1: maxElement = 3, secondMax = INT_MIN
// Iteration 2: maxElement = 3, secondMax = 1
// Iteration 3: maxElement = 7, secondMax = 3
// Iteration 4: maxElement = 9, secondMax = 7
// Iteration 5: maxElement = 9, secondMax = 7
// Output: 7

// ****************** Advantages ******************
// ✅ Optimal approach finds second largest in a single pass (O(N)).
// ✅ Space complexity is O(1), making it efficient for large arrays.

// ****************** Disadvantages ******************
// ❌ Brute force (sorting) is inefficient for large arrays (O(N log N) time).
// ❌ Sorting modifies the original array if not done on a copy.

// ****************** Summary ******************
// - Sorting-based approach is O(N log N) but unnecessary.
// - The best approach is a single-pass scan (O(N)) with O(1) space.
