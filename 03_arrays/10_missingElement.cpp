// ****************** Find Missing Element in an Array ******************

// A sequence of numbers from 1 to N (or 0 to N-1) is given, but one element is missing.
// The goal is to find the missing element efficiently.

// ************************************************************************************************************

// ****************** 1️⃣ Brute Force Approach ******************

// Explanation:
// - Iterate from 1 to N and check if each number is present in the array.
// - Use a nested loop or a linear search for each number.
// - Time Complexity: **O(N²)**
// - Space Complexity: **O(1)**

#include <bits/stdc++.h>
using namespace std;

int findMissingBrute(vector<int>& arr, int N) {
    for (int i = 1; i <= N; i++) {
        bool found = false;
        for (int num : arr) {
            if (num == i) {
                found = true;
                break;
            }
        }
        if (!found) return i;
    }
    return -1;
}

// ************************************************************************************************************

// ****************** 2️⃣ Better Approach (Using Hashing) ******************

// Explanation:
// - Use a **hash set** to store array elements.
// - Iterate from 1 to N and check which number is missing in the set.
// - Time Complexity: **O(N)**
// - Space Complexity: **O(N)**

int findMissingBetter(vector<int>& arr, int N) {
    unordered_set<int> elements(arr.begin(), arr.end());

    for (int i = 1; i <= N; i++) {
        if (elements.find(i) == elements.end()) {
            return i;
        }
    }

    return -1;
}

// ************************************************************************************************************

// ****************** 3️⃣ Optimal Approach (Using Sum Formula) ******************

// Explanation:
// - Calculate the **expected sum** of numbers from 1 to N using the formula:  
//   `sum = N * (N + 1) / 2`
// - Compute the **actual sum** of the given array.
// - The missing number is `expectedSum - actualSum`.
// - Time Complexity: **O(N)**
// - Space Complexity: **O(1)**

int findMissingOptimal(vector<int>& arr, int N) {
    int expectedSum = N * (N + 1) / 2;
    int actualSum = accumulate(arr.begin(), arr.end(), 0);

    return expectedSum - actualSum;
}

// ************************************************************************************************************

// ****************** 4️⃣ Most Optimal Approach (Using XOR) ******************

// Explanation:
// - XOR of all numbers from `1 to N` and all elements of the array will cancel out everything except the missing number.
// - `XOR(a, a) = 0` and `XOR(0, x) = x`, so missing number remains.
// - Time Complexity: **O(N)**
// - Space Complexity: **O(1)**

int findMissingXOR(vector<int>& arr, int N) {
    int xor1 = 0, xor2 = 0;

    for (int i = 1; i <= N; i++) xor1 ^= i;
    for (int num : arr) xor2 ^= num;

    return xor1 ^ xor2;
}

// ************************************************************************************************************

// ****************** 5️⃣ Time & Space Complexity ******************

// | Approach        | Time Complexity | Space Complexity |
// |----------------|----------------|------------------|
// | Brute Force    | O(N²)           | O(1)             |
// | Hashing        | O(N)            | O(N)             |
// | Sum Formula    | O(N)            | O(1)             |
// | XOR Approach   | O(N)            | O(1)             |

// ************************************************************************************************************

// ****************** 6️⃣ Dry Run ******************

// **Input:**  
// arr = [1, 2, 4, 5]  
// N = 5  

// **Brute Force:**  
// Check numbers from 1 to 5 → Missing number = **3**  

// **Better (Hashing):**  
// HashSet = {1, 2, 4, 5} → Missing = **3**  

// **Optimal (Sum Formula):**  
// Expected sum = 5*(5+1)/2 = 15  
// Actual sum = 1+2+4+5 = 12  
// Missing = **15 - 12 = 3**  

// **Most Optimal (XOR):**  
// XOR(1,2,3,4,5) ⊕ XOR(1,2,4,5) = 3  

// **Output:** 3  

// ************************************************************************************************************

// ****************** 7️⃣ Advantages & Disadvantages ******************

// ✅ **Brute Force**  
// - Simple but very slow.  
// - Inefficient for large arrays.  

// ✅ **Better Approach (Hashing)**  
// - Faster but uses extra space.  

// ✅ **Optimal Approach (Sum Formula)**  
// - Works well but can cause overflow for large N.  

// ✅ **Most Optimal Approach (XOR)**  
// - Fastest and most efficient.  
// - Works only if exactly **one** number is missing.  

// ************************************************************************************************************

// ****************** 8️⃣ Summary ******************

// ✅ The missing element in an array from 1 to N can be found using different approaches.  
// ✅ **Brute force:** Check every number, O(N²) time.  
// ✅ **Better approach:** Use a hash set, O(N) time.  
// ✅ **Optimal approach:** Use sum formula, O(N) time.  
// ✅ **Most optimal approach:** Use XOR, O(N) time, O(1) space.  
// ✅ XOR is the best approach for efficiency and memory usage.  

// ************************************************************************************************************
