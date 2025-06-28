// ****************** Remove Duplicates from Sorted Array ******************

// ****************** Problem Statement ******************
// Given a **sorted** array, remove duplicates **in-place** such that each element appears only once.
// Return the new length of the array after removing duplicates.

// ****************** Brute Force Approach ******************
// - Use a set to store unique elements and copy them back to the array.

#include <bits/stdc++.h>
using namespace std;

int removeDuplicatesBrute(vector<int>& arr) {
    set<int> s(arr.begin(), arr.end()); // Store unique elements in set
    int index = 0;
    for (int num : s) arr[index++] = num; // Copy back to array
    return index;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize = removeDuplicatesBrute(arr);
    for (int i = 0; i < newSize; i++) cout << arr[i] << " ";
    return 0;
}

// Time Complexity: O(N log N) (due to set operations)
// Space Complexity: O(N) (extra space for set)

// ****************** Better Approach ******************
// - Use two pointers: one for unique elements and another for iterating.

int removeDuplicatesBetter(vector<int>& arr) {
    if (arr.empty()) return 0;
    int index = 1; // Position for unique elements
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != arr[i - 1]) arr[index++] = arr[i];
    }
    return index;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4, 5};
    int newSize = removeDuplicatesBetter(arr);
    for (int i = 0; i < newSize; i++) cout << arr[i] << " ";
    return 0;
}

// Time Complexity: O(N) (single pass)
// Space Complexity: O(1) (in-place modification)

// ****************** Optimal Approach ******************
// - Same as better approach; no further optimization possible.

// ****************** Dry Run ******************
// Input: [1, 1, 2, 2, 3, 4, 4, 5]
// Iteration 1: arr[1] == arr[0] -> skip
// Iteration 2: arr[2] != arr[1] -> store at index 1
// Iteration 3: arr[3] == arr[2] -> skip
// Iteration 4: arr[4] != arr[3] -> store at index 2
// Output: [1, 2, 3, 4, 5] (new size = 5)

// ****************** Advantages ******************
// ✅ Optimal approach runs in O(N) time with O(1) space.
// ✅ Modifies array in-place without extra space usage.

// ****************** Disadvantages ******************
// ❌ Brute force approach uses extra space (set).

// ****************** Summary ******************
// - Sorting-based set approach is O(N log N) and inefficient.
// - Two-pointer approach (O(N)) is the best for in-place modification.
