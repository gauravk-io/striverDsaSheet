// ****************** Union of Two Sorted Arrays ******************

// ****************** Problem Statement ******************
// Given two sorted arrays, find their union without duplicates.
// Example: arr1 = [1, 2, 3, 4], arr2 = [2, 4, 6, 8] → Output: [1, 2, 3, 4, 6, 8]

// ****************** Brute Force Approach ******************
// - Insert both arrays into a set to remove duplicates.
// - Convert set to vector.

#include <bits/stdc++.h>
using namespace std;

vector<int> unionBrute(vector<int>& arr1, vector<int>& arr2) {
    set<int> s(arr1.begin(), arr1.end());
    s.insert(arr2.begin(), arr2.end());
    return vector<int>(s.begin(), s.end());
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4}, arr2 = {2, 4, 6, 8};
    vector<int> result = unionBrute(arr1, arr2);
    for (int num : result) cout << num << " ";
    return 0;
}

// Time Complexity: O(N log N) (due to set insertions)
// Space Complexity: O(N)

// ****************** Better Approach ******************
// - Use two pointers to merge arrays while avoiding duplicates.

vector<int> unionBetter(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    int i = 0, j = 0, n = arr1.size(), m = arr2.size();
    
    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) result.push_back(arr1[i++]);
        else if (arr1[i] > arr2[j]) result.push_back(arr2[j++]);
        else { 
            result.push_back(arr1[i++]); 
            j++;
        }
    }

    while (i < n) result.push_back(arr1[i++]);
    while (j < m) result.push_back(arr2[j++]);
    
    return result;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4}, arr2 = {2, 4, 6, 8};
    vector<int> result = unionBetter(arr1, arr2);
    for (int num : result) cout << num << " ";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)

// ****************** Optimal Approach ******************
// - Since the better approach is already O(N) and space-efficient, it's optimal.

vector<int> unionOptimal(vector<int>& arr1, vector<int>& arr2) {
    return unionBetter(arr1, arr2); // The better approach is already optimal
}

// ****************** Dry Run ******************
// arr1 = [1, 2, 3, 4], arr2 = [2, 4, 6, 8]
// Step 1: Compare 1 & 2 → Add 1
// Step 2: Compare 2 & 2 → Add 2, move both pointers
// Step 3: Compare 3 & 4 → Add 3
// Step 4: Compare 4 & 4 → Add 4, move both pointers
// Step 5: Append remaining [6, 8]
// Output: [1, 2, 3, 4, 6, 8]

// ****************** Advantages ******************
// ✅ Optimal approach works in O(N) with O(N) space.
// ✅ Uses two-pointer technique for efficiency.

// ****************** Disadvantages ******************
// ❌ Uses extra space for the result array (cannot be done in-place).

// ****************** Summary ******************
// - Brute force uses a set (O(N log N), O(N)).
// - Two-pointer approach is optimal (O(N), O(N)).
