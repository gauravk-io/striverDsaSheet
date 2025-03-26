// ****************** Arrays in C++ ******************

// An **array** is a **contiguous memory block** that stores elements of the **same data type**.
// Arrays allow **random access** (O(1) time complexity) using indices and are **fixed in size**.

// **Key Concepts:**
// 1. **Indexing**: Array indices start from **0**.
// 2. **Contiguous Memory**: Elements are stored sequentially in memory.
// 3. **Fixed Size**: The size is defined at the time of declaration.
// 4. **Random Access**: Any element can be accessed in **O(1) time** using an index.

// **Time Complexity:**
// - **Access:** O(1) (Direct indexing).
// - **Search:** O(n) (Linear Search) or O(log n) (Binary Search).
// - **Insertion:** O(n) (Shifting required).
// - **Deletion:** O(n) (Shifting required).

// **Space Complexity:** O(n) (Stores n elements).


// ****************** 1️⃣ Declaring and Initializing Arrays ******************

#include <bits/stdc++.h>
using namespace std;

int main() {
    // 1. Declaration
    int arr1[5];  // Uninitialized array

    // 2. Initialization
    int arr2[5] = {1, 2, 3, 4, 5};  // Initialized with values

    // 3. Partial Initialization (remaining elements are 0)
    int arr3[5] = {1, 2};  // {1, 2, 0, 0, 0}

    // 4. Automatic Size Calculation
    int arr4[] = {10, 20, 30};  // Size = 3

    return 0;
}

// Explanation:
// - Arrays can be **declared and initialized** in multiple ways.
// - If size is omitted, it is **determined automatically** from the values.


// ****************** 2️⃣ Accessing and Modifying Elements ******************

int main() {
    int arr[] = {5, 10, 15, 20, 25};

    // Accessing elements using indices
    cout << "First Element: " << arr[0] << endl;  // Output: 5

    // Modifying elements
    arr[2] = 100;
    cout << "Modified Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";  // Output: 5 10 100 20 25

    return 0;
}

// Explanation:
// - Elements are accessed using **zero-based indexing**.
// - Modifying an element replaces the value at that index.


// ****************** 3️⃣ Traversing an Array ******************

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);  // Size calculation

    cout << "Array Elements: ";
    
    // Using for loop
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

// Explanation:
// - **`sizeof(arr) / sizeof(arr[0])`** gives the number of elements in the array.
// - Traversing is **O(n) time complexity**.


// ****************** 4️⃣ Searching in an Array ******************

bool linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return true;
    }
    return false;
}

int main() {
    int arr[] = {3, 7, 1, 9, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int key = 9;
    cout << (linearSearch(arr, size, key) ? "Found" : "Not Found") << endl;

    return 0;
}

// Explanation:
// - **Linear search** checks each element **one by one** (O(n) time).
// - If the array is **sorted**, **Binary Search (O(log n))** can be used.


// ****************** 5️⃣ Insertion in an Array ******************

int insertAtEnd(int arr[], int &n, int capacity, int value) {
    if (n >= capacity) return -1;  // No space available
    arr[n++] = value;  // Insert value
    return 0;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5}; 
    int n = 5, capacity = 10;  

    insertAtEnd(arr, n, capacity, 6);

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}

// Explanation:
// - Inserting at the **end** is O(1).
// - Inserting at the **beginning/middle** is O(n) due to shifting.


// ****************** 6️⃣ Deletion in an Array ******************

void deleteElement(int arr[], int &n, int index) {
    if (index < 0 || index >= n) return;  // Invalid index

    for (int i = index; i < n - 1; i++) {
        arr[i] = arr[i + 1];  // Shift left
    }
    n--;  // Reduce size
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    deleteElement(arr, n, 2);  // Delete element at index 2

    cout << "Array after deletion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}

// Explanation:
// - **Shifting elements** makes deletion O(n).
// - Deleting from the **end** is O(1).


// ****************** 7️⃣ Dry Run of Array Operations ******************

// Given Array: {1, 2, 3, 4, 5}

// **Insertion (6 at the end)**
// - New Array: {1, 2, 3, 4, 5, 6}

// **Deletion (Index 2)**
// - Before: {1, 2, 3, 4, 5}
// - Shift left: {1, 2, 4, 5, _}
// - After: {1, 2, 4, 5} (n decreases)


// ****************** 8️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - **O(1) access time** (Direct indexing).
// - **Efficient memory usage** (contiguous storage).
// - **Best for fixed-size data storage**.

// ❌ **Disadvantages:**
// - **Fixed size** (Cannot grow dynamically).
// - **Insertion/Deletion is slow** (O(n) due to shifting).
// - **Wastes memory** if size is over-allocated.


// ****************** 🔟 Summary ******************

// ✅ **Arrays** store **fixed-size** elements in **contiguous memory**.
// ✅ Provide **O(1) access time** using indices.
// ✅ **Insertion/Deletion** is O(n) due to **shifting** elements.
// ✅ Used in **sorting, searching, and data storage**.
// ✅ **Alternative:** Use **Vectors (Dynamic Arrays)** for flexible size.

