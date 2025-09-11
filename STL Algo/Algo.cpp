#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool cIf (int n) {
    return n > 4;
}

bool absBelow1(int a, int b){ 
    return abs(a-b) <=1; 
}

int doubleX (int x) {
    return x*2;
}

int addXY (int x, int y){
    return x + y;
}

template<typename Iter>
string notFoundcheck(Iter i, Iter end){
    return i != end ? to_string(*i) : "Not Found";
}

int main() {

    vector<int> v = {1,2,3,4,5,6,6,5,4,3,3,4};

    vector<int> v1 = {2,3};


    cout << "<vector 1>for_each: ";
    for_each(v.begin(), v.end(), [](int &n) { cout << n << " "; });
    cout << endl;

    cout << "<vector 2>for_each: ";
    for_each(v1.begin(), v1.end(), [](int &n) { cout << n << " "; });
    cout << endl;

    cout << "count: ";
    int countV = count(v.begin(), v.end(), 3);
    cout << countV << "\n";

    cout << "count_if: ";
    int countIf = count_if(v.begin(), v.end(), cIf);
    cout << countIf << "\n";

    cout << "find: ";
    auto p = find(v.begin(), v.end(), 2);
    cout << notFoundcheck(p, v.end()) << endl;

    cout << "find_if: ";
    auto pIf = find_if(v.begin(), v.end(), cIf);
    cout << notFoundcheck(pIf, v.end()) << endl;

    cout << "find_first_of: ";
    auto pfo = find_first_of(v.begin(), v.end(), v1.begin(), v1.end());
    cout << notFoundcheck(pfo, v.end()) << endl;

    cout << "find_first_of (with predicate): ";
    auto pfoIf = find_first_of(v.begin(), v.end(), v1.begin(), v1.end(), absBelow1);
    cout << notFoundcheck(pfoIf, v.end()) << endl;

    cout << "equal: ";
    bool eq = equal(v.begin(), v.end(), v1.begin());
    cout << eq << endl;

    cout << "equal (with predicate): ";
    bool eqIf = equal(v.begin(), v.end(), v1.begin(), absBelow1);
    cout << eqIf << endl;

    cout << "mismatch: ";
    auto [p1, p2] = mismatch(v.begin(), v.end(), v1.begin()); 
    cout << notFoundcheck(p1, v.end()) << " " << notFoundcheck(p2, v1.end()) << endl;

    cout << "mismatch (with predicate): ";
    auto [p1f, p2f] = mismatch(v.begin(), v.end(), v1.begin(), absBelow1);
    cout << notFoundcheck(p1f, v.end()) << " " << notFoundcheck(p2f, v1.end()) << endl;

    cout << "search: ";
    auto psearch = search(v.begin(), v.end(), v1.begin(), v1.end());
    cout << notFoundcheck(psearch, v.end()) << endl;

    cout << "search (with predicate): ";
    auto psearchIf = search(v.begin(), v.end(), v1.begin(), v1.end(), absBelow1);
    cout << notFoundcheck(psearchIf, v.end()) << endl;

    cout << "search_n: ";
    auto psearch_n = search_n(v.begin(), v.end(), 2, 1);
    cout << notFoundcheck(psearch_n, v.end()) << endl;

    cout << "search_n (with predicate): ";
    auto psearch_nIf = search_n(v.begin(), v.end(), 2, 1, absBelow1);
    cout << notFoundcheck(psearch_nIf, v.end()) << endl;

    cout << "transform (unary): ";
    vector<int> doubled(v.size());
    transform(v.begin(), v.end(), doubled.begin(), doubleX);
    for (int x : doubled) cout << x << " ";
    cout << endl;

    cout << "transform (binary): ";
    vector<int> sum(v1.size());
    transform(v.begin(), v.begin() + v1.size(), v1.begin(), sum.begin(), addXY);
    for (int x : sum) cout << x << " ";
    cout << endl;

    cout << "copy: ";
    vector<int> c1(v.size());
    copy(v.begin(), v.end(), c1.begin());
    for (int x : c1) cout << x << " ";
    cout << endl;

    cout << "copy_if (n > 4): ";
    vector<int> c2;
    c2.resize(v.size());
    auto it2 = copy_if(v.begin(), v.end(), c2.begin(), cIf);
    c2.resize(distance(c2.begin(), it2));
    for (int x : c2) cout << x << " ";
    cout << endl;

    cout << "copy_n (first 5): ";
    vector<int> c3(5);
    copy_n(v.begin(), 5, c3.begin());
    for (int x : c3) cout << x << " ";
    cout << endl;

    cout << "copy_backward: ";
    vector<int> c4(v.size());
    copy_backward(v.begin(), v.end(), c4.end());
    for (int x : c4) cout << x << " ";
    cout << endl;

    cout << "move: ";
    vector<int> vMove = {10,20,30,40,50};
    vector<int> c5(vMove.size());
    move(vMove.begin(), vMove.end(), c5.begin());
    for (int x : c5) cout << x << " ";
    cout << endl;

    cout << "move_backward: ";
    vector<int> vMove2 = {100,200,300,400};
    vector<int> c6(vMove2.size());
    move_backward(vMove2.begin(), vMove2.end(), c6.end());
    for (int x : c6) cout << x << " ";
    cout << endl;


    cout << "unique: ";
    vector<int> u1 = v;  // prevent mutating the original
    auto newEnd = unique(u1.begin(), u1.end());
    u1.erase(newEnd, u1.end());   // shrink container
    for (int x : u1) cout << x << " ";
    cout << endl;

    cout << "unique (with predicate absBelow1): ";
    vector<int> u2 = v;
    auto newEnd2 = unique(u2.begin(), u2.end(), absBelow1);
    u2.erase(newEnd2, u2.end());
    for (int x : u2) cout << x << " ";
    cout << endl;

    cout << "unique_copy: ";
    vector<int> uc1(v.size());
    auto ucEnd1 = unique_copy(v.begin(), v.end(), uc1.begin());
    uc1.resize(distance(uc1.begin(), ucEnd1));
    for (int x : uc1) cout << x << " ";
    cout << endl;

    cout << "unique_copy (with predicate absBelow1): ";
    vector<int> uc2(v.size());
    auto ucEnd2 = unique_copy(v.begin(), v.end(), uc2.begin(), absBelow1);
    uc2.resize(distance(uc2.begin(), ucEnd2));
    for (int x : uc2) cout << x << " ";
    cout << endl;

    cout << "rotate: ";
    vector<int> r1 = v;  // copy v to keep original safe
    rotate(r1.begin(), r1.begin() + 3, r1.end()); // rotate by 3
    for (int x : r1) cout << x << " ";
    cout << endl;

    cout << "partition (n > 4): ";
    vector<int> partV = v;
    auto itPart = partition(partV.begin(), partV.end(), cIf);
    for (int x : partV) cout << x << " ";
    cout << endl;

    cout << "stable_partition (n > 4): ";
    vector<int> sp1 = v;
    auto itStablePart = stable_partition(sp1.begin(), sp1.end(), cIf);
    for (int x : sp1) cout << x << " ";
    cout << endl;

    cout << "is_partitioned (n > 4): ";
    bool partCheck = is_partitioned(v.begin(), v.end(), cIf);
    cout << (partCheck ? "true" : "false") << endl;


    return 0;
}