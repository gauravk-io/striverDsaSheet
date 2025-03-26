// ****************** Left Rotate Array by K Places ******************

// ****************** Problem Statement ******************
// Given an array of size N, rotate it **left** by K places.
// Example: arr = [1, 2, 3, 4, 5], K = 2 → Output: [3, 4, 5, 1, 2]

// ****************** Brute Force Approach ******************
// - Use an extra array to store rotated values.

#include <bits/stdc++.h>
using namespace std;

void rotateBrute(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n; // Handle cases where K > N
    vector<int> temp(arr.begin() + k, arr.end()); // Store rotated part
    temp.insert(temp.end(), arr.begin(), arr.begin() + k); // Append initial elements
    arr = temp;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    rotateBrute(arr, k);
    for (int num : arr) cout << num << " ";
    return 0;
}

// Time Complexity: O(N) (copying elements)
// Space Complexity: O(N) (extra array)

// ****************** Better Approach ******************
// - Shift elements one by one (K times).

void rotateBetter(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    while (k--) {
        int first = arr[0];
        for (int i = 0; i < n - 1; i++) arr[i] = arr[i + 1];
        arr[n - 1] = first;
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    rotateBetter(arr, k);
    for (int num : arr) cout << num << " ";
    return 0;
}

// Time Complexity: O(N * K) (shifting K times)
// Space Complexity: O(1)

// ****************** Optimal Approach ******************
// - Reverse three parts: [0, K-1], [K, N-1], then whole array.

void reverseArray(vector<int>& arr, int start, int end) {
    while (start < end) swap(arr[start++], arr[end--]);
}

void rotateOptimal(vector<int>& arr, int k) {
    int n = arr.size();
    k = k % n;
    reverseArray(arr, 0, k - 1);   // Reverse first K elements
    reverseArray(arr, k, n - 1);   // Reverse remaining elements
    reverseArray(arr, 0, n - 1);   // Reverse entire array
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;
    rotateOptimal(arr, k);
    for (int num : arr) cout << num << " ";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(1)

// ****************** Dry Run ******************
// Input: [1, 2, 3, 4, 5], K = 2
// Step 1: Reverse first K elements → [2, 1, 3, 4, 5]
// Step 2: Reverse remaining elements → [2, 1, 5, 4, 3]
// Step 3: Reverse full array → [3, 4, 5, 1, 2]
// Output: [3, 4, 5, 1, 2]

// ****************** Advantages ******************
// ✅ Optimal approach runs in O(N) time with O(1) space.
// ✅ Works efficiently for large arrays.

// ****************** Disadvantages ******************
// ❌ Brute force uses extra space (not in-place).
// ❌ Better approach is slow for large K values.

// ****************** Summary ******************
// - Extra array approach is O(N) but uses extra space.
// - Shifting one by one is inefficient (O(N*K)).
// - Reversal method is best (O(N), O(1)).
