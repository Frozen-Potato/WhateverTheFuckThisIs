#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    // === unordered_set ===
    cout << "\n=== unordered_set ===\n";
    unordered_set<int> us = {5, 1, 3, 5, 2};
    us.insert(4);
    us.insert(1); // duplicate ignored

    cout << "Contents (order not guaranteed, unique): ";
    for (int x : us) cout << x << " ";
    cout << "\nFind 3: " << (us.count(3) ? "found" : "not found") << endl;

    // === unordered_multiset ===
    cout << "\n=== unordered_multiset ===\n";
    unordered_multiset<int> ums = {5, 1, 3, 5, 2};
    ums.insert(3);

    cout << "Contents (order not guaranteed, duplicates allowed): ";
    for (int x : ums) cout << x << " ";
    cout << "\nCount of 3: " << ums.count(3) << endl;

    // === unordered_map ===
    cout << "\n=== unordered_map ===\n";
    unordered_map<string, int> um;
    um["apple"] = 3;
    um["banana"] = 5;
    um.insert({"orange", 2});

    cout << "Contents (unordered key-value, unique keys):\n";
    for (auto &p : um) {
        cout << p.first << " => " << p.second << "\n";
    }
    cout << "banana count: " << um.count("banana") << endl;

    // === unordered_multimap ===
    cout << "\n=== unordered_multimap ===\n";
    unordered_multimap<string, int> umm;
    umm.insert({"apple", 3});
    umm.insert({"apple", 5});
    umm.insert({"banana", 2});

    cout << "Contents (unordered key-value, duplicate keys allowed):\n";
    for (auto &p : umm) {
        cout << p.first << " => " << p.second << "\n";
    }
    cout << "apple count: " << umm.count("apple") << endl;

    return 0;
}
