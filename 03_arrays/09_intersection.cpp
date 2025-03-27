// ****************** Intersection of Two Sorted Arrays ******************

// ****************** Problem Statement ******************
// Given two sorted arrays, find their intersection (common elements).
// Example: arr1 = [1, 2, 2, 3, 4], arr2 = [2, 2, 4, 6] → Output: [2, 2, 4]

// ****************** Brute Force Approach ******************
// - Use a hash map to store element frequencies from one array.
// - Iterate through the second array and check for common elements.

#include <bits/stdc++.h>
using namespace std;

vector<int> intersectionBrute(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freq;
    vector<int> result;

    for (int num : arr1) freq[num]++;  // Store frequencies of arr1
    for (int num : arr2) {
        if (freq[num] > 0) {  // If exists in map, add to result
            result.push_back(num);
            freq[num]--;  // Reduce count to handle duplicates correctly
        }
    }

    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4}, arr2 = {2, 2, 4, 6};
    vector<int> result = intersectionBrute(arr1, arr2);
    for (int num : result) cout << num << " ";
    return 0;
}

// Time Complexity: O(N + M)
// Space Complexity: O(N) (due to hash map)

// ****************** Better Approach ******************
// - Use two pointers to traverse both arrays.

vector<int> intersectionBetter(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0, n = arr1.size(), m = arr2.size();

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) i++;
        else if (arr1[i] > arr2[j]) j++;
        else {
            result.push_back(arr1[i]);
            i++; j++;
        }
    }
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 2, 3, 4}, arr2 = {2, 2, 4, 6};
    vector<int> result = intersectionBetter(arr1, arr2);
    for (int num : result) cout << num << " ";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// ****************** Optimal Approach ******************
// - The better approach is already optimal as it runs in O(N) time and O(1) space.

vector<int> intersectionOptimal(vector<int>& arr1, vector<int>& arr2) {
    return intersectionBetter(arr1, arr2);
}

// ****************** Dry Run ******************
// arr1 = [1, 2, 2, 3, 4], arr2 = [2, 2, 4, 6]
// Step 1: Compare 1 & 2 → Move i
// Step 2: Compare 2 & 2 → Add 2, move both
// Step 3: Compare 2 & 2 → Add 2, move both
// Step 4: Compare 3 & 4 → Move i
// Step 5: Compare 4 & 4 → Add 4, move both
// Step 6: arr1 exhausted → Stop
// Output: [2, 2, 4]

// ****************** Advantages ******************
// ✅ Uses two-pointer technique, runs in O(N).
// ✅ No extra space used (in-place approach).

// ****************** Disadvantages ******************
// ❌ Only works if arrays are sorted.
// ❌ Doesn't handle duplicate removal automatically (if required).

// ****************** Summary ******************
// - Brute force uses hash maps (O(N + M), O(N)).
// - Two-pointer approach is optimal (O(N), O(1)).
