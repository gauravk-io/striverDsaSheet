
// ****************** Max Consecutive 1s in an Array ******************

// Given a binary array (containing only 0s and 1s), find the maximum number of consecutive 1s.

// ************************************************************************************************************

// ****************** 1️⃣ Brute Force Approach ******************

// Explanation:
// - Iterate through the array and start counting 1s whenever a 1 is found.
// - If a 0 is encountered, update the max count and reset the current count.
// - Time Complexity: **O(N²)**
// - Space Complexity: **O(1)**

#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnesBrute(vector<int>& arr) {
    int n = arr.size();
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            int count = 0;
            for (int j = i; j < n && arr[j] == 1; j++) {
                count++;
            }
            maxCount = max(maxCount, count);
        }
    }
    return maxCount;
}

// ************************************************************************************************************

// ****************** 2️⃣ Better Approach ******************

// Explanation:
// - Traverse the array once while keeping a count of consecutive 1s.
// - If a 0 is encountered, update the max count and reset the current count.
// - Time Complexity: **O(N)**
// - Space Complexity: **O(1)**

int maxConsecutiveOnesBetter(vector<int>& arr) {
    int maxCount = 0, count = 0;

    for (int num : arr) {
        if (num == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }

    return maxCount;
}

// ************************************************************************************************************

// ****************** 3️⃣ Optimal Approach (Same as Better) ******************

// Explanation:
// - The better approach is already optimal (single pass with O(1) space).
// - There's no further optimization possible beyond **O(N)** time complexity.
// - Time Complexity: **O(N)**
// - Space Complexity: **O(1)**

int maxConsecutiveOnesOptimal(vector<int>& arr) {
    return maxConsecutiveOnesBetter(arr);
}

// ************************************************************************************************************

// ****************** 4️⃣ Time & Space Complexity ******************

// | Approach       | Time Complexity | Space Complexity |
// |---------------|----------------|------------------|
// | Brute Force   | O(N²)           | O(1)             |
// | Better        | O(N)            | O(1)             |
// | Optimal       | O(N)            | O(1)             |

// ************************************************************************************************************

// ****************** 5️⃣ Dry Run ******************

// **Input:**  
// arr = [1, 1, 0, 1, 1, 1]

// **Brute Force:**  
// - Start at index 0 → count = 2 → maxCount = 2  
// - Start at index 3 → count = 3 → maxCount = **3**  

// **Better Approach:**  
// - Count resets at 0 → maxCount = **3**  

// **Output:** 3  

// ************************************************************************************************************

// ****************** 6️⃣ Advantages & Disadvantages ******************

// ✅ **Brute Force**  
// - Simple but very slow for large arrays.  

// ✅ **Better Approach (Optimal)**  
// - Fast, single pass solution.  
// - No extra space required.  

// ❌ **No further optimization possible beyond O(N).**  

// ************************************************************************************************************

// ****************** 7️⃣ Summary ******************

// ✅ Finding the maximum consecutive 1s in a binary array is best solved in **O(N)** time.  
// ✅ **Brute force:** Check every sequence, O(N²) time.  
// ✅ **Better approach:** Single pass tracking count, O(N) time, **most efficient**.  

// ************************************************************************************************************
