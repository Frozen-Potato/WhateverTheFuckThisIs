#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <array>
#include <iterator>  // for advance

using namespace std;

void printSequenceContainer(auto &n){
    for (int x: n) cout << x << " ";
}

int main() {
    //  vector 
    cout << "\nVector \n";
    vector<int> v = {1, 2, 3};
    v.push_back(4);               // add at end
    v.insert(v.begin() + 1, 10);  // insert at index 1
    v.erase(v.begin() + 2);       // erase at index 2

    cout << "Contents: ";
    printSequenceContainer(v);
    cout << "\nFront: " << v.front() << "\nBack: " << v.back() << endl;

    //  deque 
    cout << "\nDeque \n";
    deque<int> dq = {1, 2, 3};
    dq.push_front(0);   // add at front
    dq.push_back(4);    // add at back
    dq.pop_front();     // remove from front

    cout << "Contents: ";
    printSequenceContainer(dq);
    cout << "\nFront: " << dq.front() << "\nBack: " << dq.back() << endl;

    //  list 
    cout << "\nList \n";
    list<int> lst = {1, 2, 3};
    auto it = lst.begin();
    advance(it, 1);      // move iterator to 2nd element
    lst.insert(it, 10);  // insert before 2
    lst.remove(3);       // remove all 3’s

    cout << "Contents: ";
    printSequenceContainer(lst);
    cout << endl;

    //  forward_list 
    cout << "\nForward_list \n";
    forward_list<int> fwdLst = {1, 2, 3};
    fwdLst.push_front(0);              // insert at front
    auto fit = fwdLst.begin();
    fwdLst.insert_after(fit, 10);      // insert after 0

    cout << "Contents: ";
    printSequenceContainer(fwdLst);
    cout << endl;

    //  array 
    cout << "\nArray \n";
    array<int, 5> arr = {1, 2, 3, 4, 5};
    arr[2] = 10;   // random access

    cout << "Contents: ";
    printSequenceContainer(arr);
    cout << "\nSize: " << arr.size() << endl;

    return 0;
}
