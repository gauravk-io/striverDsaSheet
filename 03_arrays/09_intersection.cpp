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




// **************************************************************************************************************

// ****************** Intersection of Two Unsorted Arrays ******************

// The **intersection** of two arrays contains only the common elements between them.
// In unsorted arrays, we must efficiently find and handle duplicates.

// ************************************************************************************************************

// ****************** 1️⃣ Brute Force Approach ******************

// Explanation:
// - Compare each element of the first array with every element of the second array.
// - If a match is found, check if it is already in the result array to avoid duplicates.
// - Time Complexity: **O(N*M)**
// - Space Complexity: **O(min(N, M))** (For storing intersection elements)

vector<int> intersectionBrute(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;

    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                bool found = false;
                for (int k = 0; k < result.size(); k++) {
                    if (result[k] == arr1[i]) {
                        found = true;
                        break;
                    }
                }
                if (!found) result.push_back(arr1[i]);
            }
        }
    }
    
    return result;
}

// ************************************************************************************************************

// ****************** 2️⃣ Better Approach ******************

// Explanation:
// - Use **unordered_set** for quick lookup.
// - Store all elements of the smaller array in a set.
// - Iterate through the larger array and check if elements exist in the set.
// - Time Complexity: **O(N + M)**
// - Space Complexity: **O(min(N, M))** (For the set)

vector<int> intersectionBetter(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<int> elements;
    unordered_set<int> resultSet;
    
    // Store elements of the smaller array in a set
    if (arr1.size() > arr2.size()) swap(arr1, arr2);
    
    for (int num : arr1) {
        elements.insert(num);
    }
    
    // Check for common elements
    for (int num : arr2) {
        if (elements.find(num) != elements.end()) {
            resultSet.insert(num);
        }
    }
    
    return vector<int>(resultSet.begin(), resultSet.end());
}

// ************************************************************************************************************

// ****************** 3️⃣ Optimal Approach ******************

// Explanation:
// - Use **unordered_map** to track frequencies in the first array.
// - Iterate through the second array and check if elements exist in the map.
// - If found, add to result and reduce frequency to prevent duplicates.
// - Time Complexity: **O(N + M)**
// - Space Complexity: **O(min(N, M))** (For the map)

vector<int> intersectionOptimal(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> freqMap;
    vector<int> result;

    // Store frequency of elements in the first array
    for (int num : arr1) {
        freqMap[num]++;
    }

    // Check for common elements in the second array
    for (int num : arr2) {
        if (freqMap[num] > 0) {
            result.push_back(num);
            freqMap[num] = 0; // Ensuring each element is added only once
        }
    }

    return result;
}

// ************************************************************************************************************

// ****************** 4️⃣ Time & Space Complexity ******************

// | Approach       | Time Complexity | Space Complexity |
// |---------------|----------------|------------------|
// | Brute Force   | O(N*M)          | O(min(N, M))    |
// | Better        | O(N + M)        | O(min(N, M))    |
// | Optimal       | O(N + M)        | O(min(N, M))    |

// ************************************************************************************************************

// ****************** 5️⃣ Dry Run ******************

// **Input:**  
// arr1 = [1, 3, 4, 6, 7]  
// arr2 = [2, 3, 6, 8]  

// **Brute Force:**  
// Step 1: Compare each element of arr1 with arr2  
// Step 2: Found 3 → Add to result  
// Step 3: Found 6 → Add to result  
// **Final Output:** [3, 6]  

// **Better/Optimal:**  
// Step 1: Store elements of arr1 in a set/map → {1, 3, 4, 6, 7}  
// Step 2: Check arr2 elements in set/map  
// Step 3: Found 3, 6 → Add to result  
// **Final Output:** [3, 6]  

// ************************************************************************************************************

// ****************** 6️⃣ Advantages & Disadvantages ******************

// ✅ **Brute Force**  
// - Simple but slow.  
// - Inefficient for large arrays.  

// ✅ **Better Approach (Set)**  
// - Efficient lookup (O(1) avg case).  
// - Uses extra space.  

// ✅ **Optimal Approach (Map)**  
// - Prevents duplicate insertions.  
// - Uses extra space for frequency tracking.  

// ************************************************************************************************************

// ****************** 7️⃣ Summary ******************

// ✅ Intersection finds common elements between two arrays.  
// ✅ **Brute force:** Nested loops, O(N*M) time.  
// ✅ **Better approach:** Hash set, O(N + M) time.  
// ✅ **Optimal approach:** Hash map, O(N + M) time (prevents duplicates).  
// ✅ **Use sets/maps** for efficient lookup.  

// ************************************************************************************************************
