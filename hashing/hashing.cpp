// ****************** Hashing ******************

// **Hashing** is a technique used to **map data to a fixed-size table** using a **hash function**.
// It is mainly used in **fast data retrieval** (O(1) average time complexity).
// Hashing is used in **hash tables, databases, caching, password storage**, etc.

// **Key Concepts:**
// 1. **Hash Function**: Converts a key into an index for a hash table.
// 2. **Collision Handling**: When two keys hash to the same index, we resolve conflicts using:
//    - **Chaining** (Linked List at each index).
//    - **Open Addressing** (Linear/Quadratic Probing, Double Hashing).
// 3. **Load Factor**: Measures hash table efficiency (`n / table_size`).

// **Time Complexity:**
// - **Best Case:** O(1) (Direct access via hash function).
// - **Worst Case:** O(n) (All elements collide in the same index).
// - **Average Case:** O(1) (With good hash function & low load factor).

// **Space Complexity:**
// - O(n) (Storage for keys and values).


// ****************** 1️⃣ Implementation of Hash Table (Chaining) ******************

#include <bits/stdc++.h>
using namespace std;

// Hash Table using Separate Chaining
class HashTable {
private:
    int size;
    vector<list<int>> table;  // Array of linked lists for chaining

    // Hash function
    int hashFunction(int key) {
        return key % size;
    }

public:
    // Constructor
    HashTable(int s) {
        size = s;
        table.resize(size);
    }

    // Insert key into hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Search for a key
    bool search(int key) {
        int index = hashFunction(key);
        for (int x : table[index]) {
            if (x == key) return true;
        }
        return false;
    }

    // Remove a key
    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            for (int x : table[i]) cout << x << " -> ";
            cout << "NULL" << endl;
        }
    }
};

// ****************** 2️⃣ Testing the Hash Table ******************

int main() {
    HashTable ht(7);  // Hash table with size 7

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);

    cout << "Hash Table after insertion:" << endl;
    ht.display();

    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 5: " << (ht.search(5) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "Hash Table after deleting 15:" << endl;
    ht.display();

    return 0;
}

// Explanation:
// - **hashFunction()** maps keys to an index.
// - **insert()** places the key in the list at the corresponding index.
// - **search()** checks if the key exists at the index.
// - **remove()** deletes the key if found.


// ****************** 3️⃣ Dry Run of Hash Table ******************

// Given hash table size: 7
// Insert: 10, 20, 15, 7

// **Hash Function (key % 7)**
// - 10 % 7 → Index 3 → [10]
// - 20 % 7 → Index 6 → [20]
// - 15 % 7 → Index 1 → [15]
// - 7 % 7  → Index 0 → [7]

// **Search for 15**
// - 15 % 7 → Index 1 → Found in the list.


// ****************** 4️⃣ Advantages and Disadvantages ******************

// ✅ **Advantages:**
// - **O(1) average time complexity** for search, insert, and delete.
// - **Efficient memory usage** (does not store unnecessary elements).
// - **Used in many real-world applications** (databases, caches, dictionaries).

// ❌ **Disadvantages:**
// - **Collisions affect performance**, especially with poor hash functions.
// - **Extra space required** for chaining (linked lists).
// - **Performance degrades** as the load factor increases.


// ****************** 5️⃣ Summary ******************

// ✅ **Hashing** provides **O(1) average time complexity** for **search, insert, and delete**.
// ✅ **Collision handling** is done via **chaining** (linked lists) or **open addressing** (probing).
// ✅ Used in **hash tables, caches, password storage, databases**.
// ✅ Works efficiently when the **load factor is low**.
// ✅ Choosing a **good hash function** is key to performance.

