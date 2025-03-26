// ****************** Move Zeros to End ******************

// ****************** Problem Statement ******************
// Given an array, move all zeros to the end while maintaining the order of non-zero elements.
// Example: arr = [0, 1, 0, 3, 12] → Output: [1, 3, 12, 0, 0]

// ****************** Brute Force Approach ******************
// - Use an extra array to store non-zero elements, then append zeros.

#include <bits/stdc++.h>
using namespace std;

void moveZerosBrute(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp;
    
    for (int num : arr) 
        if (num != 0) temp.push_back(num);
    
    while (temp.size() < n) temp.push_back(0);
    
    arr = temp;
}

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZerosBrute(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N) (extra array)

// ****************** Better Approach ******************
// - Shift non-zero elements forward, then fill remaining positions with zeros.

void moveZerosBetter(vector<int>& arr) {
    int n = arr.size(), j = 0;
    
    for (int i = 0; i < n; i++)
        if (arr[i] != 0) arr[j++] = arr[i];

    while (j < n) arr[j++] = 0;
}

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZerosBetter(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// ****************** Optimal Approach ******************
// - Use **two-pointer technique** to swap zeros with non-zero elements.

void moveZerosOptimal(vector<int>& arr) {
    int j = 0; // Points to the first zero
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) swap(arr[i], arr[j++]); // Swap and move j forward
    }
}

int main() {
    vector<int> arr = {0, 1, 0, 3, 12};
    moveZerosOptimal(arr);
    for (int num : arr) cout << num << " ";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// ****************** Dry Run ******************
// Input: [0, 1, 0, 3, 12]
// Step 1: Swap 0 with 1 → [1, 0, 0, 3, 12]
// Step 2: Skip 0, Swap 0 with 3 → [1, 3, 0, 0, 12]
// Step 3: Swap 0 with 12 → [1, 3, 12, 0, 0]
// Output: [1, 3, 12, 0, 0]

// ****************** Advantages ******************
// ✅ Optimal approach works in O(N) with O(1) space.
// ✅ Maintains relative order of non-zero elements.

// ****************** Disadvantages ******************
// ❌ Brute force uses extra space (not in-place).

// ****************** Summary ******************
// - Brute force uses extra array (O(N) space).
// - Better approach shifts elements (O(N), O(1)).
// - Optimal **two-pointer** approach swaps elements efficiently (O(N), O(1)).
