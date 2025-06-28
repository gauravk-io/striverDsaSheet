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



// ***************************************************************************************************************************


// ****************** Union of Two Unsorted Arrays ******************

// The **union** of two arrays means combining all unique elements from both arrays.
// In unsorted arrays, we need to handle duplicates and ensure all elements appear only once.

// ************************************************************************************************************

// ****************** 1️⃣ Brute Force Approach ******************

// Explanation:
// - Insert all elements from both arrays into a new array.
// - Use a nested loop to remove duplicates.
// - Time Complexity: **O(N*M)**
// - Space Complexity: **O(N + M)** (Storing all elements)

vector<int> unionBrute(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;
    
    // Insert all elements of arr1
    for (int i = 0; i < arr1.size(); i++) {
        result.push_back(arr1[i]);
    }
    
    // Insert all elements of arr2 if not already present
    for (int i = 0; i < arr2.size(); i++) {
        bool found = false;
        for (int j = 0; j < result.size(); j++) {
            if (arr2[i] == result[j]) {
                found = true;
                break;
            }
        }
        if (!found) result.push_back(arr2[i]);
    }
    
    return result;
}

// ************************************************************************************************************

// ****************** 2️⃣ Better Approach ******************

// Explanation:
// - Use **unordered_set** to store unique elements.
// - Insert all elements from both arrays.
// - Convert set back to vector and return the result.
// - Time Complexity: **O(N + M)**
// - Space Complexity: **O(N + M)** (Hash set storage)

vector<int> unionBetter(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> uniqueElements;

    // Insert elements from both arrays
    for (int num : arr1) uniqueElements.insert(num);
    for (int num : arr2) uniqueElements.insert(num);

    // Convert set to vector
    vector<int> result(uniqueElements.begin(), uniqueElements.end());
    return result;
}

// ************************************************************************************************************

// ****************** 3️⃣ Optimal Approach ******************

// Explanation:
// - Similar to the better approach but uses **unordered_map** to maintain counts.
// - Useful if we need to track frequencies.
// - Time Complexity: **O(N + M)**
// - Space Complexity: **O(N + M)** (Unordered map storage)

vector<int> unionOptimal(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freqMap;

    // Store frequency of each element
    for (int num : arr1) freqMap[num]++;
    for (int num : arr2) freqMap[num]++;

    // Extract keys to form the union
    vector<int> result;
    for (auto it : freqMap) {
        result.push_back(it.first);
    }
    
    return result;
}

// ************************************************************************************************************

// ****************** 4️⃣ Time & Space Complexity ******************

// | Approach       | Time Complexity | Space Complexity |
// |---------------|----------------|------------------|
// | Brute Force   | O(N*M)          | O(N + M)        |
// | Better        | O(N + M)        | O(N + M)        |
// | Optimal       | O(N + M)        | O(N + M)        |

// ************************************************************************************************************

// ****************** 5️⃣ Dry Run ******************

// **Input:**  
// arr1 = [1, 3, 5, 7]  
// arr2 = [2, 3, 6, 7]  

// **Brute Force:**  
// Step 1: result = [1, 3, 5, 7]  
// Step 2: Add 2 (not in result) → [1, 3, 5, 7, 2]  
// Step 3: Skip 3 (already in result)  
// Step 4: Add 6 → [1, 3, 5, 7, 2, 6]  
// Step 5: Skip 7 (already in result)  
// **Final Output:** [1, 3, 5, 7, 2, 6]  

// **Better/Optimal:**  
// Step 1: Insert all elements in set/map → {1, 2, 3, 5, 6, 7}  
// **Final Output:** [1, 2, 3, 5, 6, 7]  

// ************************************************************************************************************

// ****************** 6️⃣ Advantages & Disadvantages ******************

// ✅ **Brute Force**  
// - Simple to implement.  
// - Inefficient for large arrays.  

// ✅ **Better Approach (Set)**  
// - Efficient insertion and lookup (O(1) avg case).  
// - Uses extra space.  

// ✅ **Optimal Approach (Map)**  
// - Tracks frequencies if needed.  
// - Still requires additional space.  

// ************************************************************************************************************

// ****************** 7️⃣ Summary ******************

// ✅ Union of two unsorted arrays requires handling duplicates.  
// ✅ **Brute force:** Nested loops, O(N*M) time.  
// ✅ **Better approach:** Hash set, O(N + M) time.  
// ✅ **Optimal approach:** Hash map, O(N + M) time (useful if frequencies matter).  
// ✅ **Use sets/maps** for efficient lookup and duplicate removal.  

// ************************************************************************************************************
