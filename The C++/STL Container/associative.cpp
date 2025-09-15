#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

int main() {
    // === set ===
    cout << "\n=== set ===\n";
    set<int> s = {5, 1, 3, 5, 2};
    s.insert(4);
    s.insert(1); // duplicate ignored

    cout << "Contents (sorted, unique): ";
    for (int x : s) cout << x << " ";
    cout << "\nFind 3: " << (s.count(3) ? "found" : "not found") << endl;

    // === multiset ===
    cout << "\n=== multiset ===\n";
    multiset<int> ms = {5, 1, 3, 5, 2};
    ms.insert(3);

    cout << "Contents (sorted, duplicates allowed): ";
    for (int x : ms) cout << x << " ";
    cout << "\nCount of 3: " << ms.count(3) << endl;

    // === map ===
    cout << "\n=== map ===\n";
    map<string, int> m;
    m["apple"] = 3;
    m["banana"] = 5;
    m.insert({"orange", 2});

    cout << "Contents (sorted by key):\n";
    for (auto &p : m) {
        cout << p.first << " => " << p.second << "\n";
    }
    cout << "banana count: " << m.count("banana") << endl;

    // === multimap ===
    cout << "\n=== multimap ===\n";
    multimap<string, int> mm;
    mm.insert({"apple", 3});
    mm.insert({"apple", 5});
    mm.insert({"banana", 2});

    cout << "Contents (sorted, duplicate keys allowed):\n";
    for (auto &p : mm) {
        cout << p.first << " => " << p.second << "\n";
    }
    cout << "apple count: " << mm.count("apple") << endl;

    return 0;
}
